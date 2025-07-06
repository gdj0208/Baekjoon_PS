class Alg:
    def solve(self) :
        arr = self.get_arr()
        arr.sort()
        num_min, num_max = self.get_target(arr)
        print(num_min, num_max)

    def get_arr(self) : 
        size = int(input())
        arr = list(map(int, input().split())) 
        return arr
    
    def get_target(self, arr) :
        s = 0
        e = len(arr) - 1 

        num_min = arr[s]
        num_max = arr[e]
        min_diff = num_min + num_max

        while( s < e):
            sum = arr[s] + arr[e]

            if abs(sum) < abs(min_diff) : 
                min_diff = sum
                num_min = arr[s]
                num_max = arr[e]

            if sum == 0:
                return arr[s], arr[e]
            elif sum < 0 :
                s += 1
            else :
                e -= 1
        
        return num_min, num_max

alg = Alg()
alg.solve()

'''
6
1 2 3 4 5 6
'''

