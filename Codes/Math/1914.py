
def hanoi_tower(n, start, end, sub) :
    if n == 1 :
        print(start, end)
        return 

    hanoi_tower(n-1, start, sub, end)
    print(start, end)
    hanoi_tower(n-1, sub, end, start)

floor = int(input())
print(2 ** floor - 1)

if floor <= 20 :
    hanoi_tower(floor, 1,2,3)