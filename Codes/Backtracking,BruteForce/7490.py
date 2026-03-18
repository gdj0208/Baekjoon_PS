import copy

def ret_func(str, n, max):
    if n > max :
        cpy = f"{str}".replace(" ", "")
        if eval(cpy) == 0:
            print(f"{str}")
        return 
    
    ret_func(f"{str}{' '}{n}", n+1, max)
    ret_func(f"{str}{'+'}{n}", n+1, max)
    ret_func(f"{str}{'-'}{n}", n+1, max)

rpt = int(input())
for _ in range(rpt):
    num = int(input())
    ret_func("1", 2, num)
    print()