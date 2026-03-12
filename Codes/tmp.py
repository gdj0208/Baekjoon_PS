
num = int(input())
if num <= 9 : 
    print(1)
else :
    is_odd = num%2

    if num%9 == 0:
        print(num // 9)
    else :
        if is_odd :
            print(num // 9 + 1)
        else :
            print(num // 9)


"""
몫 홀 : +2
몫 짝 : +1
"""