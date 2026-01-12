class Alg:
    arr = []
    string = str()
    
    def __init__(self):
        self.get_string()
        self.print()

    def print(self):
        for i in self.arr:
            print(i,end='')

    def get_string(self):
        self.string : str = str(input())
        self.arr = list(self.string)
        self.arr.sort(reverse=True)
    
alg = Alg()