
class Alg:
    def solve(self):
        size_of_nums = int(input())
        nums = self.get_nums(size_of_nums)
        sums = self.get_sums(nums)
        sums.sort()
        max_sum = 0

        for k in range(size_of_nums-1, -1, -1):
            for j in range(k-1, -1, -1):
                target = nums[k] - nums[j]

                tmp = self.get_max_sum(sums, target)
                if tmp != 0:
                    max_sum = max(max_sum, nums[k])

        print(max_sum)

    def get_nums(self, size_of_nums):
        nums = []

        for _ in range(size_of_nums):
            nums.append(int(input()))

        return nums
    
    def get_sums(self, nums):
        sums = []
        size = len(nums)
        
        for i in range(size):
            for j in range(i, size):
                sums.append(nums[i] + nums[j])

        return sums
    

    def get_max_sum(self, sums, target) :
        s = 0
        e = len(sums)-1

        while(s < e) :
            m = (s + e) // 2 
            sum = sums[m]

            if sum < target :
                s = m + 1
            elif sum > target :
                e = m
            else :
                return target
            
        return 0


alg = Alg()
alg.solve()