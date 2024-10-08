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
        if not line.strip().startswith(('1.', '2.', '3.', '4.')) and not line.strip().startswith('```'):
            clean_lines.append(line)
    return '\n'.join(clean_lines).strip()


def update_files(problem_description, problem_code, solution_code, test_case_code, problem_index):
    with open(f'src/student_{problem_index}.cpp', 'w') as solution_file:
        solution_file.write(problem_code.strip())

    with open(f'src/solution_{problem_index}.cpp', 'w') as solution_file:
        solution_file.write(solution_code.strip())

    with open(f'tests/test_cases_{problem_index}.txt', 'w') as test_file:
        test_file.write(test_case_code.strip())

    with open('README.md', 'a') as readme_file:
        readme_file.write(f"## 문제 {problem_index + 1}\n\n")
        readme_file.write(f"{problem_description.strip()}\n\n---\n\n")


def compile_and_run_cpp(file_path, test_file_path, problem_index):
    # Compile the C++ code
    compile_command = f"g++ {file_path} -o test_program_{problem_index}"
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

    test_results = []  # Collect results to append to README.md

    for i, (input_value, expected_output) in enumerate(test_cases):
        # Prepare input data for the C++ program
        input_data = input_value.strip().replace('[', '').replace(']', '').replace(',', '\n') + "\n"
        expected_output = expected_output.strip()

        run_process = subprocess.run(
            [f"./test_program_{problem_index}"],
            input=input_data, 
            capture_output=True,
            text=True
        )

        actual_output = run_process.stdout.strip()
        if actual_output == expected_output:
            passed_tests += 1
            test_results.append(f"테스트 케이스 {i+1}: 성공 (입력: {input_value}, 결과: {actual_output})")
        else:
            test_results.append(f"테스트 케이스 {i+1}: 실패 (입력: {input_value}, 기대값: {expected_output}, 결과: {actual_output})")

    result_summary = f"{passed_tests}/{total_tests} 테스트 케이스 통과"
    test_results.append(result_summary)

    # Append test results to README.md
    with open('README.md', 'a') as readme_file:
        readme_file.write(f"### 문제 {problem_index + 1} 테스트 결과\n")
        readme_file.write("\n".join(test_results) + "\n\n---\n\n")

    print(result_summary)


def main():
    prompts = [
        """
        C++ 프로그래밍 문제를 생성하세요.
        난이도는 어려운 문제로 설정해주세요.
        테스트 케이스는 10개에서 20개 정도 생성해주세요. 각 테스트 케이스는 '입력값 => 예상 출력값' 형식으로 제공해야합니다.
        아래는 형식을 보여주는 예시 코드입니다. 아래 형식을 지키면서 새로운 문제를 생성해주세요. 
        그리고 ---로 각각의 번호를 구분할겁니다. 각 번호가 끝날 때마다 ---을 넣어주세요. 그 외에는 ---을 추가해서는 안됩니다.:
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
            cin >> number;
            cout << square(number) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
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
            cin >> number;
            cout << square(number) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
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
        C++ 프로그래밍 문제를 생성하세요.
        난이도는 어려운 문제로 설정해주세요.
        테스트 케이스는 10개에서 20개 정도 생성해주세요. 각 테스트 케이스는 '입력값 => 예상 출력값' 형식으로 제공해야합니다.
        아래는 형식을 보여주는 예시 코드입니다. 아래 형식을 지키면서 새로운 문제를 생성해주세요. 
        그리고 ---로 각각의 번호를 구분할겁니다. 각 번호가 끝날 때마다 ---을 넣어주세요. 그 외에는 ---을 추가해서는 안됩니다.:
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
            cin >> num1 >> num2;
            cout << sum(num1, num2) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
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
            cin >> num1 >> num2;
            cout << sum(num1, num2) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
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
        """
        C++ 프로그래밍 문제를 생성하세요.
        난이도는 어려운 문제로 설정해주세요.
        테스트 케이스는 10개에서 20개 정도 생성해주세요. 각 테스트 케이스는 '입력값 => 예상 출력값' 형식으로 제공해야합니다.
        아래는 형식을 보여주는 예시 코드입니다. 아래 형식을 지키면서 새로운 문제를 생성해주세요. 
        그리고 ---로 각각의 번호를 구분할겁니다. 각 번호가 끝날 때마다 ---을 넣어주세요. 그 외에는 ---을 추가해서는 안됩니다.:
        1. 자연어 문제 설명
        사용자로부터 두 개의 정수를 입력받아 두 정수의 차를 계산하여 출력하는 프로그램을 작성하시오.
        ---

        2. 문제 코드
        ```cpp
        #include <iostream>
        using namespace std;

        int difference(int a, int b) {
            // 여기에 코드를 작성하세요.
        }

        int main() {
            int num1, num2;
            cin >> num1 >> num2;
            cout << difference(num1, num2) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
            return 0;
        }
        ```

        ---

        3. 정답 코드
        ```cpp
        #include <iostream>
        using namespace std;

        int difference(int a, int b) {
            return a - b;
        }

        int main() {
            int num1, num2;
            cin >> num1 >> num2;
            cout << difference(num1, num2) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
            return 0;
        }
        ```

        ---

        4. 테스트 케이스
        5,3 => 2
        20,10 => 10
        1,1 => 0
        7,8 => -1
        0,0 => 0
        -5,5 => -10
        200,100 => 100
        456,123 => 333
        50,25 => 25
        -100,50 => -150
        """,
        """
        C++ 프로그래밍 문제를 생성하세요.
        난이도는 어려운 문제로 설정해주세요.
        테스트 케이스는 10개에서 20개 정도 생성해주세요. 각 테스트 케이스는 '입력값 => 예상 출력값' 형식으로 제공해야합니다.
        아래는 형식을 보여주는 예시 코드입니다. 아래 형식을 지키면서 새로운 문제를 생성해주세요. 
        그리고 ---로 각각의 번호를 구분할겁니다. 각 번호가 끝날 때마다 ---을 넣어주세요. 그 외에는 ---을 추가해서는 안됩니다.:
        1. 자연어 문제 설명
        사용자로부터 두 개의 정수를 입력받아 두 정수의 곱을 계산하여 출력하는 프로그램을 작성하시오.
        ---

        2. 문제 코드
        ```cpp
        #include <iostream>
        using namespace std;

        int product(int a, int b) {
            // 여기에 코드를 작성하세요.
        }

        int main() {
            int num1, num2;
            cin >> num1 >> num2;
            cout << product(num1, num2) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
            return 0;
        }
        ```

        ---

        3. 정답 코드
        ```cpp
        #include <iostream>
        using namespace std;

        int product(int a, int b) {
            return a * b;
        }

        int main() {
            int num1, num2;
            cin >> num1 >> num2;
            cout << product(num1, num2) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
            return 0;
        }
        ```

        ---

        4. 테스트 케이스
        5,3 => 15
        2,10 => 20
        1,1 => 1
        7,8 => 56
        0,10 => 0
        -5,5 => -25
        10,10 => 100
        6,7 => 42
        50,2 => 100
        -10,5 => -50
        """,
        """
        C++ 프로그래밍 문제를 생성하세요.
        난이도는 어려운 문제로 설정해주세요.
        테스트 케이스는 10개에서 20개 정도 생성해주세요. 각 테스트 케이스는 '입력값 => 예상 출력값' 형식으로 제공해야합니다.
        아래는 형식을 보여주는 예시 코드입니다. 아래 형식을 지키면서 새로운 문제를 생성해주세요. 
        그리고 ---로 각각의 번호를 구분할겁니다. 각 번호가 끝날 때마다 ---을 넣어주세요. 그 외에는 ---을 추가해서는 안됩니다.:
        1. 자연어 문제 설명
        사용자로부터 세 개의 정수를 입력받아 가장 큰 수를 출력하는 프로그램을 작성하시오.
        ---

        2. 문제 코드
        ```cpp
        #include <iostream>
        using namespace std;

        int maxOfThree(int a, int b, int c) {
            // 여기에 코드를 작성하세요.
        }

        int main() {
            int num1, num2, num3;
            cin >> num1 >> num2 >> num3;
            cout << maxOfThree(num1, num2, num3) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
            return 0;
        }
        ```

        ---

        3. 정답 코드
        ```cpp
        #include <iostream>
        using namespace std;

        int maxOfThree(int a, int b, int c) {
            if (a > b && a > c) return a;
            if (b > a && b > c) return b;
            return c;
        }

        int main() {
            int num1, num2, num3;
            cin >> num1 >> num2 >> num3;
            cout << maxOfThree(num1, num2, num3) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
            return 0;
        }
        ```

        ---

        4. 테스트 케이스
        1,2,3 => 3
        3,2,1 => 3
        5,5,5 => 5
        0,-1,1 => 1
        -10,-5,-1 => -1
        100,50,25 => 100
        123,456,789 => 789
        -5,0,5 => 5
        50,50,100 => 100
        9,9,8 => 9
        """
    ]

    for idx, prompt in enumerate(prompts):
        print(f"문제 {idx+1} 생성 및 테스트 시작...")
        problem_text = generate_problem(prompt)
        parts = problem_text.split('---')
        if len(parts) < 4:
            print(f"문제 {idx+1} 생성 오류: 생성된 텍스트 형식이 올바르지 않습니다.")
            continue

        problem_description = clean_text(parts[0])
        problem_code = clean_text(parts[1])
        solution_code = clean_text(parts[2])
        test_case_code = clean_text(parts[3])
        update_files(problem_description, problem_code, solution_code, test_case_code, idx)

        print(f"문제 {idx+1} 컴파일 및 테스트 실행...")
        if compile_and_run_cpp(f'src/solution_{idx}.cpp', f'tests/test_cases_{idx}.txt', idx):
            run_tests()
        print(f"문제 {idx+1} 완료.\n")


if __name__ == "__main__":
    main()
