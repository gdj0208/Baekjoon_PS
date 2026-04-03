
INF = float('inf')

customer_in_need, num_city = map(int, input().split())
costs = [list(map(int, input().split())) for _ in range(num_city)]

MAX_customer = customer_in_need + 100
dp = [INF for _ in range(MAX_customer)]
dp[0] = 0

for cost, customer in costs :
    for i in range(customer, MAX_customer) :
        dp[i] = min(dp[i], dp[i-customer] + cost)

print(min(dp[customer_in_need:]))