
class Alg:
    def __init__(self) :
        self.num_size, self.num_erase = map(int, input().split())
        tmp = int(input())
        self.num = [int(i) for i in str(tmp)]

    def solve(self):
        self.stk = []
        for i in range(self.num_size):
            if not self.stk:
                self.stk.append(self.num[i])
                continue

            while self.stk and self.stk[-1] < self.num[i] and self.num_erase > 0:
                self.stk.pop()
                self.num_erase -= 1
                
            self.stk.append(self.num[i]) 

        while self.num_erase > 0:
            self.stk.pop()
            self.num_erase -= 1
        
        self.stk = self.stk[:self.num_size - self.num_erase]
        print(''.join(map(str, self.stk)))


alg = Alg()
alg.solve()