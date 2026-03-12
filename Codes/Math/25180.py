def get_minimum_length(n):
    l = 1
    while True:
        max_sum = 9 * l
        
        if l % 2 == 0:
            if n % 2 == 0 and n <= max_sum:
                return l
        else:
            if n <= max_sum:
                return l
            
        l += 1

n = int(input())
print(get_minimum_length(n))