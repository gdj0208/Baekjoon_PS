from collections import deque

def operate(operation, li):
    is_reversed = False

    for op in operation:
        if op == 'R':
            is_reversed = False if is_reversed else True
        else :
            if len(li) == 0:
                print("error")
                return
            
            if is_reversed :
                li.pop()
            else :
                li.popleft()

    if is_reversed:
        li.reverse()
    print("[" + ",".join(li) + "]")


rpt = int(input())
for _ in range(rpt):
    operation = input()
    size = int(input())

    input_str = input()[1:-1] 
    if input_str == "":
        li = deque()
    else:
        li = deque(input_str.split(','))
    
    operate(operation, li)