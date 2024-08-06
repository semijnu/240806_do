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
        solution_file.write(problem_code.strip())

    with open('tests/test_solution.cpp', 'w') as test_file:
        test_file.write(test_case_code.strip())

def compile_and_run_cpp(file_path):
    # Compile the C++ code
    compile_command = f"g++ {file_path} -o test_program"
    compile_process = subprocess.run(compile_command, shell=True, capture_output=True, text=True)

    if compile_process.returncode != 0:
        print("컴파일 오류:", compile_process.stderr)
        return

    # Run the compiled program
    run_process = subprocess.run("./test_program", shell=True, capture_output=True, text=True)
    
    if run_process.returncode != 0:
        print("프로그램 실행 오류:", run_process.stderr)
    else:
        print("프로그램 실행 결과:", run_process.stdout)

prompt = """
C++ 프로그래밍 문제를 생성하세요.

아래는 형식을 보여주는 예시 코드입니다. 아래 형식을 지키면서 새로운 문제를 생성해주세요. 문제 생성시 제목은 빼고 생성해주세요(예: 1. 자연어 문제 설명, 2. 문제 코드 등). 그리고 ---로 각각의 번호를 구분할겁니다. 각 번호가 끝날 때마다 ---을 넣어주세요.:
1. 자연어 문제 설명
---

2. 문제 코드(프로그램의 대략적인 구조를 보여주는 기본 코드)
---

3. 정답 코드
---

4. 테스트 케이스

"""  # 닫는 삼중 따옴표
problem = generate_problem(prompt)
update_files(problem)
