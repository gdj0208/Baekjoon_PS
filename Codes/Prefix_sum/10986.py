
ans = 0

def make_sum_list(my_list, div_num) :
    global ans
    total_sum = 0
    sum_list = [0] * div_num

    for n in my_list :
        total_sum = (total_sum + n) % div_num
        if total_sum == 0:
            ans += 1
        sum_list[total_sum] += 1

    return sum_list

def get_cnt(list, size, div_num) :
    global ans
    for cnt in list :
        if cnt >= 2:
            ans += (cnt * (cnt-1))//2

def solve() :
    size, div_num = map(int, input().split())
    my_list = list(map(int, input().split()))
    sum_list = make_sum_list(my_list, div_num)
    get_cnt(sum_list, size, div_num)
    print(ans)

solve()