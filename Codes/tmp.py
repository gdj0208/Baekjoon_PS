
h, w = map(int, input().split())

sum = 0
max_height = 0
max_left = [0 for _ in range(w)]
max_right = [0 for _ in range(w)]
get = list(map(int, input().split()))
ans = []

m_left = 0
m_right = 0
for i in range(w):
    m_left = m_left if m_left > get[i] else get[i]
    max_left[i] = m_left

    m_right = m_right if m_right > get[w-1-i] else get[w-1-i]
    max_right[w-1-i] = m_right

for i in range(w):
    tmp = min(max_left[i], max_right[i]) - get[i]
    ans.append(tmp)
    sum += tmp

# print("max_left : ", max_left)
# print("max_right : ", max_right)
# print("get : " ,get)
print(sum)