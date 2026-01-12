
class Alg() :
    def __init__(self):
        self.arr = []
        self.dp = []
        self.cnt = []

    def get(self):
        self.size = int(input())
        for i in range(alg.size):
            num = int(input())
            self.arr.append(num)
            self.dp.append(0)
            self.cnt.append(0)

        if self.size == 1:
            return self.arr[0]
        elif self.size == 2:
            return self.arr[0] + self.arr[1]
        elif self.size == 3:
            return max(self.arr[0], self.arr[1]) + self.arr[2]

        self.dp[0] = self.arr[0]
        self.dp[1] = self.arr[0] + self.arr[1]
        self.dp[2] = max(self.arr[0], self.arr[1]) + self.arr[2]

        for i in range(3, self.size):
            a = self.dp[i-2] + self.arr[i]
            b = self.dp[i-3] + self.arr[i-1] + self.arr[i]
            self.dp[i] = max(a, b)
        
        return self.dp[-1]
        


alg = Alg()
print(alg.get())