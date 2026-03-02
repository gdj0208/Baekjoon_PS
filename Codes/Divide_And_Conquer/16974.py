N, X = map(int, input().split())

burger_len = [0] * 51
patty_cnt = [0] * 51

burger_len[0] = 1
patty_cnt[0] = 1

for i in range(1, 51):
    burger_len[i] = 2 * burger_len[i - 1] + 3
    patty_cnt[i] = 2 * patty_cnt[i - 1] + 1

def get_patty(n, x):
    if n == 0:
        return 1
    
    if x == 1:
        return 0
    elif x <= 1 + burger_len[n - 1]:
        return get_patty(n - 1, x - 1)
    elif x == 1 + burger_len[n - 1] + 1:
        return patty_cnt[n - 1] + 1
    elif x < burger_len[n]:
        return patty_cnt[n - 1] + 1 + get_patty(n - 1, x - (1 + burger_len[n - 1] + 1))
    else:
        return patty_cnt[n]

print(get_patty(N, X))