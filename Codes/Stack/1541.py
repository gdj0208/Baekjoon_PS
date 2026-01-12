class Alg:
    def __init__(self):
        self.str = str(input())
        self.numStk = []
        self.calStk = []
        self.num = 0
    
    def get_min(self):
        for c in self.str:
            if self.is_num(c):
                self.num = 10 * self.num + int(c)
            else :
                self.numStk.append(int(self.num))
                self.num = 0

                while len(self.calStk) != 0 and self.calStk[-1] == '+':
                    self.numStk.append(self.numStk.pop() + self.numStk.pop())
                    self.calStk.pop()

                self.calStk.append(c)
        
        self.numStk.append(int(self.num))
        self.num = 0

        while len(self.calStk) != 0 and self.calStk[-1] == '+':
            self.numStk.append(self.numStk.pop() + self.numStk.pop())
            self.calStk.pop()

        while len(self.calStk) != 0:
            cal = self.calStk.pop(0)
            n1 = self.numStk.pop(0)
            n2 = self.numStk.pop(0)

            self.numStk.insert(0, n1 - n2)

        return self.numStk.pop()
    
    def is_num(self, c):
        return '0' <= c <= '9'

alg = Alg()
min = alg.get_min()
print(min)