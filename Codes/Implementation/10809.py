class Alg:
    def __init__(self):
        self.string : str = str(input())
        self.is_used = {'a':-1, 'b':-1, 'c':-1, 'd':-1, 'e':-1, 'f':-1, 'g':-1, 'h':-1, 'i':-1, 'j':-1, 'k':-1, 'l':-1, 'm':-1, 'n':-1, 'o':-1, 'p':-1, 'q':-1, 'r':-1, 's':-1, 't':-1, 'u':-1, 'v':-1, 'w':-1, 'x':-1, 'y':-1, 'z':-1}

    def get_locations(self):
        for charic in self.string:
            self.is_used[charic] = self.string.index(charic)
        
        for n in self.is_used.values():
            print(n, end=' ')
    
alg = Alg()
alg.get_locations()