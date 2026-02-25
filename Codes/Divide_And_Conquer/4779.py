
def change(start, end):
    if start == end:
        print("-")
        return

    diff = end - start
    div = diff // 3

    if div == 1:
        print("-", end="")
        print(" ", end="")
        print("-", end="")
    else :
        change(start , start + div)
        for _ in range(div):
            print(" ", end="")
        change(start+2*div, end)

while True:
    try:
        num = input()
        if num == "":
            break

        num = int(num)
        start = 0
        end = pow(3, num)

        if num == 0:
            print("-")
        else :
            change(start, end)
            print()
    except:
        break