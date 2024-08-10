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
    # Remove section headers and code block delimiters
    lines = text.split('\n')
    clean_lines = []
    for line in lines:
        if not line.strip().startswith(tuple(map(str, range(1, 5)))) and not line.strip().startswith('```'):
            clean_lines.append(line)
    return '\n'.join(clean_lines).strip()

def update_files(problem_description, problem_code, solution_code, test_case_code, problem_index):
    with open(f'src/student_{problem_index}.cpp', 'w') as solution_file:
        solution_file.write(problem_code.strip())

    with open(f'src/solution_{problem_index}.cpp', 'w') as solution_file:
        solution_file.write(solution_code.strip())

    with open(f'tests/test_cases_{problem_index}.txt', 'w') as test_file:
        test_file.write(test_case_code.strip())

def compile_and_run_cpp(file_path, test_file_path):
    # Compile the C++ code
    compile_command = f"g++ {file_path} -o test_program"
    compile_process = subprocess.run(compile_command, shell=True, capture_output=True, text=True)

    if compile_process.returncode != 0:
        print("컴파일 오류:", compile_process.stderr)
        return False

    # Run tests
    with open(test_file_path, 'r') as test_file:
        raw_test_cases = test_file.read().strip().split("\n")

    test_cases = []
    for raw_test_case in raw_test_cases:
        if '=>' not in raw_test_case:
            print(f"테스트 케이스 형식 오류: {raw_test_case.strip()}")
            continue

        input_value, expected_output = map(str.strip, raw_test_case.split('=>'))
        test_cases.append((input_value, expected_output))

    total_tests = len(test_cases)
    passed_tests = 0

    for i, (input_value, expected_output) in enumerate(test_cases):
        # Prepare input data for the C++ program
        input_data = input_value.strip().replace('[', '').replace(']', '').replace(',', '\n') + "\n"
        expected_output = expected_output.strip()

        run_process = subprocess.run(
            ["./test_program"],
            input=input_data.encode(),  # 인코딩된 입력 데이터 사용
            capture_output=True,
            text=True
        )
        
        actual_output = run_process.stdout.strip()
        if actual_output == expected_output:
            passed_tests += 1
        else:
            print(f"테스트 케이스 {i+1} 실패: 입력={input_value}, 기대값={expected_output}, 결과={actual_output}")

    print(f"{passed_tests}/{total_tests} 테스트 케이스 통과")

def main():
    prompts = [
        """
        1. 자연어 문제 설명
        사용자로부터 정수 하나를 입력 받아 그 정수의 제곱을 계산하여 출력하는 프로그램을 작성하시오. 이때 입력은 정수형으로 주어집니다.
        ---

        2. 문제 코드
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
        ```

        ---

        3. 정답 코드
        ```cpp
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
        ```

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
        """,
        """
        1. 자연어 문제 설명
        사용자로부터 입력받은 두 정수의 합을 출력하는 프로그램을 작성하시오.
        ---

        2. 문제 코드
        ```cpp
        #include <iostream>
        using namespace std;

        int sum(int a, int b) {
            // 여기에 코드를 작성하세요.
        }

        int main() {
            int num1, num2;
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "The sum is: " << sum(num1, num2) << endl;
            return 0;
        }
        ```

        ---

        3. 정답 코드
        ```cpp
        #include <iostream>
        using namespace std;

        int sum(int a, int b) {
            return a + b;
        }

        int main() {
            int num1, num2;
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "The sum is: " << sum(num1, num2) << endl;
            return 0;
        }
        ```

        ---

        4. 테스트 케이스
        3,5 => 8
        10,20 => 30
        -1,1 => 0
        7,8 => 15
        0,0 => 0
        -5,-5 => -10
        100,200 => 300
        123,456 => 579
        50,50 => 100
        -100,100 => 0
        """,
        # ... 추가적인 문제들을 이와 같은 형식으로 생성하세요 ...
    ]

    for idx, prompt in enumerate(prompts):
        print(f"문제 {idx+1} 생성 및 테스트 시작...")
        problem_text = generate_problem(prompt)
        problem_description, problem_code, solution_code, test_case_code = problem_text.split('---')
        update_files(problem_description, problem_code, solution_code, test_case_code, idx)

        print(f"문제 {idx+1} 컴파일 및 테스트 실행...")
        if compile_and_run_cpp(f'src/solution_{idx}.cpp', f'tests/test_cases_{idx}.txt'):
            run_tests()
        print(f"문제 {idx+1} 완료.\n")

if __name__ == "__main__":
    main()
