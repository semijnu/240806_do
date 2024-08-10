import openai
import os
import subprocess

def generate_problem(prompt):
    api_key = os.getenv('OPENAI_API_KEY')
    if not api_key:
        raise ValueError("API key is missing or invalid")
    openai.api_key = api_key
    
    response = openai.chat.completions.create(
        model="gpt-4",
        messages=[
            {"role": "system", "content": "You are a helpful assistant."},
            {"role": "user", "content": prompt}
        ]
    )
    
    return response.choices[0].message.content.strip()

def clean_text(text):
    # Remove section headers like "1. 자연어 문제 설명", "2. 문제 코드", etc. and Markdown code block delimiters
    lines = text.split('\n')
    clean_lines = []
    for line in lines:
        if not line.strip().startswith(tuple(map(str, range(1, 5)))) and not line.strip().startswith('```'):
            clean_lines.append(line)
    return '\n'.join(clean_lines).strip()

def update_files(problem_text):
    parts = problem_text.split('---')
    print(parts)
    if len(parts) < 4:
        print("생성된 텍스트:", problem_text)
        raise ValueError("생성된 문제 텍스트 형식이 올바르지 않습니다.")
    
    problem_description, problem_code, solution_code, test_case_code = map(clean_text, parts[:4])

    with open('README.md', 'w') as readme_file:
        readme_file.write(f"# 과제 설명\n\n## 문제 설명\n{problem_description.strip()}\n\n## 제출 방법\n1. `src/solution.cpp` 파일을 수정하여 문제를 해결하세요.\n2. 완료되면, 변경 사항을 커밋하고 푸시하세요.\n")

    with open('src/solution.cpp', 'w') as solution_file:
        solution_file.write(solution_code.strip())

    with open('tests/test_cases.txt', 'w') as test_file:
        test_file.write(test_case_code.strip())

def compile_and_run_cpp(file_path):
    # Compile the C++ code
    compile_command = f"g++ {file_path} -o test_program"
    compile_process = subprocess.run(compile_command, shell=True, capture_output=True, text=True)

    if compile_process.returncode != 0:
        print("컴파일 오류:", compile_process.stderr)
        return False

    return True

def run_tests():
    # Run the compiled program with each test case
    with open('tests/test_cases.txt', 'r') as test_file:
        test_cases = test_file.read().strip().split("\n\n")  # 빈 줄로 구분

    total_tests = len(test_cases)
    passed_tests = 0

    for i, test_case in enumerate(test_cases):
        try:
            input_value, expected_output = map(str.strip, test_case.split('=>'))
            input_values = input_value.replace("입력값:", "").strip().split(',')
            expected_outputs = expected_output.replace("예상 출력값:", "").strip().split(',')

            # Prepare input data for the C++ program
            input_data = "\n".join(input_values)

        except ValueError:
            print(f"테스트 케이스 {i+1} 형식 오류: {test_case.strip()}")
            continue
        
        run_process = subprocess.run(
            ["./test_program"],
            input=f"{input_data}\n".encode(),  # 입력을 바이트로 직접 제공
            capture_output=True,
            text=True
        )
        
        actual_output = run_process.stdout.strip().split('\n')
        if len(actual_output) == len(expected_outputs) and all(
            act.strip() == exp.strip() for act, exp in zip(actual_output, expected_outputs)):
            passed_tests += 1
        else:
            print(f"테스트 케이스 {i+1} 실패: 입력={input_value}, 기대값={expected_output}, 결과={actual_output}")

    print(f"{passed_tests}/{total_tests} 테스트 케이스 통과")

prompt = """
C++ 프로그래밍 문제를 생성하세요.
난이도는 어려운 문제로 설정해주세요.
테스트 케이스는 10개에서 20개 정도 생성해주세요. 각 테스트 케이스는 '입력값 => 예상 출력값' 형식으로 제공해야합니다.
아래는 형식을 보여주는 예시 코드입니다. 아래 형식을 지키면서 새로운 문제를 생성해주세요. 문제 생성시 제목은 빼고 생성해주세요(예: 1. 자연어 문제 설명, 문제 코드(프로그램의 대략적인 구조를 보여주는 기본 코드), 3. 정답 코드, 4. 테스트 케이스 등). 
그리고 ---로 각각의 번호를 구분할겁니다. 각 번호가 끝날 때마다 ---을 넣어주세요. 그 외에는 ---을 추가해서는 안됩니다.:
1. 자연어 문제 설명
사용자로부터 정수 하나를 입력 받아 그 정수의 제곱을 계산하여 출력하는 프로그램을 작성하시오. 이때 입력은 정수형으로 주어집니다.
---

2. 문제 코드(프로그램의 대략적인 구조를 보여주는 기본 코드)
```cpp
#include <iostream>
using namespace std;

int square(int n) {
    // 여기에 코드를 작성하세요.
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "The square of " << number << " is: " << square(number) << endl;
    return 0;
}
---

3. 정답 코드
#include <iostream>
using namespace std;

int square(int n) {
    return n * n;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "The square of " << number << " is: " << square(number) << endl;
    return 0;
}

---

4. 테스트 케이스
5 => 25
10 => 100
-3 => 9
7 => 49
0 => 0
1 => 1
-10 => 100
15 => 225
20 => 400
-5 => 25
"""  # 닫는 삼중 따옴표
problem = generate_problem(prompt)
update_files(problem)

if compile_and_run_cpp('src/solution.cpp'):
    run_tests()
