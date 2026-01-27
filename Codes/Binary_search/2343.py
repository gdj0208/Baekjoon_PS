
import sys

def get_dvd_req(list, max):
    sum = 0
    cnt = 1
    for num in list :
        if sum + num > max :
            cnt += 1
            sum = 0
        sum += num
    return cnt


def find_num(list, list_size, num_dvd) :
    start = max(list)
    end = sum(list)

    while(start <= end) :
        mid = (start + end) // 2
        dvd_req = get_dvd_req(list, mid)

        if dvd_req > num_dvd :
            start = mid + 1
        else :
            end = mid - 1
    return start

num_arr, num_dvd = map(int, input().split())
arr = list(map(int, input().split()))

print(find_num(arr, num_arr, num_dvd))