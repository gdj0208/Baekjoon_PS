
p = [1,1,1,2,2,3]

rpt = int(input())
for i in range(6, 100):
    p.append(p[i-1] + p[i-5])

for i in range(rpt):
    n = int(input())
    print(p[n-1])