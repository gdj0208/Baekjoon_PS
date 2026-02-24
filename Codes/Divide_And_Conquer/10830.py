
def mat_mul(mat1, mat2, size) :
    new_mat = [[0 for _ in range(size)] for _ in range(size)]
    for j in range(size) :
        for i in range(size) :
            for k in range(size) :
                new_mat[j][i] += mat1[j][k] * mat2[k][i]
            new_mat[j][i] %= 1000
    return new_mat

def pow_mat(mat, rpt, size):
    if rpt == 1:
        return [[x % 1000 for x in i] for i in mat]
    
    half_pow = pow_mat(mat, rpt//2, size)

    if rpt % 2 == 0 :
        return mat_mul(half_pow, half_pow, size)
    else :
        return mat_mul(mat_mul(half_pow, half_pow, size), mat, size)
    
size, rpt = map(int, input().split())
mat = []

for j in range(size):
    nums = list(map(int, input().split()))
    mat.append(nums)

ans_mat = pow_mat(mat, rpt, size)
for j in range(size):
    for i in range(size):
        print(ans_mat[j][i], end = " ")
    print()

"""
[ 풀이 ]

문제 요소
    1. 해당 문제는 간단히 행렬 제곱을 구현하거나 라이브러리를 이용하면 될 것 같아 보인다.
    2. 그러나 행렬 제곱이 최대 100,000,000,000번 일어날 수 있고 시간 제한이 최대 1초이다
    3. 즉 간단히 행렬 제곱을 활용하는 문제가 아니다!

문제 해결
    1. 이는 분할 정복을 이용한 제곱을 활용하면 해결이 가능하다
    2. 이 기법을 활용하면 시간 복잡도를 O(n) -> O(log n)으로 줄일 수 있다

풀이 방법
    1. 다음의 공식을 활용하면 된다.
        A^b = A^(b//2) x A^(b//2) : (b가 짝수)
        A^b = A^(b//2) x A^(b//2) x A : (b가 홀수)
    2. 예를 들어 A^11일 경우
        A^11 = A^(5) x A^(5) x A
        A^5 = A^2 x A^2 x A
        A^2 = A x A
    3. 이를 구현하여 문제를 풀면 되겠다
"""