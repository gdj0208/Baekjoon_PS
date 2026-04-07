
def get_decrease_nums(num, lists) :
    lists.append(num)
    last_num = num % 10
    num *= 10
    for i in range(0, last_num) :
        get_decrease_nums(num+i, lists)

lists = []
for i in range(10) :
    get_decrease_nums(i, lists)
lists.sort()
#print(lists)

num = int(input())
if num >= len(lists) :
    print(-1)
else :
    print(lists[num])