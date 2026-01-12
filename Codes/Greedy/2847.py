
class Alg:
    def solve(self) :
        rpt = int(input())

        nums = self.get_nums(rpt)
        print(self.get_dimminish_count(nums))

    def get_nums(self, rpt):
        nums = []
        for _ in range(rpt):
            nums.append(int(input()))
        return nums

    def get_dimminish_count(self, nums):
        comp , new = -1,0
        sum = 0

        for num in reversed(nums):
            new = num

            if comp <= new and comp != -1:
                dif = new - comp + 1
                sum += dif
                comp = new - dif
            else:
                comp = new
        return(sum)

alg = Alg()
alg.solve()