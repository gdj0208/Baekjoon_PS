
import math

n1, n2 = map(int, input().split())
ans = math.sqrt(n1 * n2)
print(ans, ans)

"""
## **[ 풀이 과정 ]**

x_(n+1) = (x_n + y_n) / 2 
y_(n+1) = 2*(x_n * y_n) / (x_n + y_n)
입니다.

---
### 1. 두 식의 곱을 계산하여 불변량 찾기
- 주어진 두 점화식을 곱해봅니다.
    x_(n+1) * y_(n+1) = (x_n + y_n) / 2 * 2*(x_n * y_n) / (x_n + y_n)
                      = (x_n * y_n)
- 즉 n이 아무리 커져도 두 항의 곱은 초기값의 곱과 항상 같습니다.

---
### 2. 기하 평균 적용

- x_n * y_n = x_0 * y_0 입니다. 
- 이 수열의 x_n과 y_n은 \sqrt{x_0 * y_0}으로 수렴합니다.
"""