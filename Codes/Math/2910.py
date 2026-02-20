from collections import Counter

n1, n2 = map(int, input().split())
nums = list(map(int, input().split()))

def frequency_sort(arr):
    # 1. 각 요소의 빈도수를 계산합니다.
    counts = Counter(arr)
    
    # 2. 처음 등장한 위치(인덱스)를 기록합니다. (빈도가 같을 때를 대비)
    first_appearance = {}
    for idx, val in enumerate(arr):
        if val not in first_appearance:
            first_appearance[val] = idx

    # 3. 정렬 기준 설정:
    #   기준 1: 빈도수 (counts[x]) -> 내림차순 (-)
    #   기준 2: 첫 등장 인덱스 (first_appearance[x]) -> 오름차순 (+)
    result = sorted(arr, key=lambda x: (-counts[x], first_appearance[x]))
    
    for num in result:
        print(num, end=" ")

frequency_sort(nums)