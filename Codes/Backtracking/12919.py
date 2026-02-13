import sys

str1 = str(input())
str2 = str(input())

def solve(current_t):
    # 목표 문자열 S와 같아지면 성공
    if current_t == str1:
        print(1)
        sys.exit()
    
    # S보다 짧아지면 더 이상 탐색 불필요
    if len(current_t) <= len(str1):
        return

    # 규칙 1의 역순: 끝이 'A'이면 제거
    if current_t[-1] == 'A':
        solve(current_t[:-1])
    
    # 규칙 2의 역순: 앞이 'B'이면 제거하고 뒤집기
    if current_t[0] == 'B':
        solve(current_t[1:][::-1])

solve(str2)
print(0)

"""
풀이 :
    1. str1 -> str2로 복기하면 매 단계마다 
            1. A를 붙인다
            2. B를 붙이고 뒤집는다
            위 2개를 선택해야한다.
        -  따라서 문자열이 길수록 경우의 수가 기하급수적으로 늘어난다.
    
    2. 그래서 str1 <- str2로 복기한다.
        - 규칙 1 : 문자열에 A를 추가 -> 맨 뒤가 A라면 제거한다
        - 규칙 2 : 문자열에 B를 추가하고 뒤집니는다 -> 맨 앞이 B라면 뒤집고 맨 뒤를 뺀다

    3. str1의 길이와 str2의 길이가 같을 때 두 문자열이 일치하는지를 검사한다.
"""
