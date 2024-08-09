import openai
import os
import subprocess

def generate_problem(prompt):
    api_key = os.getenv('OPENAI_API_KEY')
    if not api_key:
        raise ValueError("API key is missing or invalid")
    openai.api_key = api_key
    
    response = openai.ChatCompletion.create(
        model="gpt-4",
        messages=[
            {"role": "system", "content": "You are a helpful assistant."},
            {"role": "user", "content": prompt}
        ]
    )
    
    return response.choices[0].message.content.strip()

def update_files(problem_text):
    parts = problem_text.split('---')
    print(parts)
    if len(parts) < 4:
        print("생성된 텍스트:", problem_text)
        raise ValueError("생성된 문제 텍스트 형식이 올바르지 않습니다.")
    
    problem_description, problem_code, solution_code, test_case_code = parts[:4]

    with open('README.md', 'w') as readme_file:
        readme_file.write(f"# 과제 설명\n\n## 문제 설명\n{problem_description.strip()}\n\n## 제출 방법\n1. `src/solution.cpp` 파일을 수정하여 문제를 해결하세요.\n2. `tests/test_solution.cpp` 파일을 통해 테스트를 확인하세요.\n3. 완료되면, 변경 사항을 커밋하고 푸시하세요.\n")

    with open('src/solution.cpp', 'w') as solution_file:
        solution_file.write(solution_code.strip())

    with open('tests/test_solution.cpp', 'w') as test_file:
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
    with open('tests/test_solution.cpp', 'r') as test_file:
        test_cases = test_file.readlines()
    
    total_tests = len(test_cases)
    passed_tests = 0
    
    for i, test_case in enumerate(test_cases):
        expected_output = test_case.split('=>')[1].strip()  # Assuming format: "input => expected_output"
        run_process = subprocess.run(
            ["./test_program"],
            input=test_case.split('=>')[0].strip().encode(),
            capture_output=True,
            text=True
        )
        
        actual_output = run_process.stdout.strip()
        if actual_output == expected_output:
            passed_tests += 1
        else:
            print(f"테스트 케이스 {i+1} 실패: 입력={test_case.strip()} 기대값={expected_output}, 결과={actual_output}")

    print(f"{passed_tests}/{total_tests} 테스트 케이스 통과")

prompt = """
C++ 프로그래밍 문제를 생성하세요.
문제 범위는 다음과 같습니다.: 자료형, 상수와 변수, 입출력 함수, 조건문, 반복문, 배열, 2차원 배열, 클래스와 객체
클래스와 객체 문제를 생성해주세요.
아래는 형식을 보여주는 예시 코드입니다. 아래 형식을 지키면서 새로운 문제를 생성해주세요. 문제 생성시 제목은 빼고 생성해주세요(예: 1. 자연어 문제 설명, 문제 코드(프로그램의 대략적인 구조를 보여주는 기본 코드), 3. 정답 코드, 4. 테스트 케이스 등). 
그리고 ---로 각각의 번호를 구분할겁니다. 각 번호가 끝날 때마다 ---을 넣어주세요. 그 외에는 ---을 추가해서는 안됩니다.:
1. 자연어 문제 설명
---

2. 문제 코드(프로그램의 대략적인 구조를 보여주는 기본 코드)
---

3. 정답 코드
---

4. 테스트 케이스(10개에서 20개 정도 생성해줘). 각 테스트 케이스는 '입력값 => 예상 출력값' 형식으로 제공해줘
"""  # 닫는 삼중 따옴표
problem = generate_problem(prompt)
update_files(problem)

if compile_and_run_cpp('src/solution.cpp'):
    run_tests()
