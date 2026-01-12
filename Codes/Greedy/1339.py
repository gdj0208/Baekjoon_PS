class Alg :
    def __init__(self):
        self.words = [{'A':0}, {'B':0}, {'C':0}, {'D':0}, {'E':0},
                      {'F':0}, {'G':0}, {'H':0}, {'I':0}, {'J':0},
                      {'K':0}, {'L':0}, {'M':0}, {'N':0}, {'O':0},
                      {'P':0}, {'Q':0}, {'R':0}, {'S':0}, {'T':0},
                      {'U':0}, {'V':0}, {'W':0}, {'X':0}, {'Y':0},
                      {'Z':0}]

    def solve(self) :
        self.get_nums()
        # self.print_sums()
        self.words.sort(key=lambda x: list(x.values())[0], reverse=True)
        print(self.return_sum()) 

    def get_nums(self):
        n = int(input())
        for i in range(n):
            word = str(input())
            self.get_word_num(word)

    def get_word_num(self, word):
        num = 10**(len(word)-1)
        for character in word:

            self.words[ord(character) - ord('A')][character] += num
            num //= 10

    def return_sum(self):
        num = 9
        sum = 0
        for key in self.words:

            for k, v in key.items():
                if v == 0:
                    break
                v *= num
                num -= 1
                sum += v
        return sum

    def print_sums(self):
        for key in self.words:
            for k, v in key.items():
                if v != 0:
                    print(f"{k} {v}")

alg = Alg()
alg.solve()