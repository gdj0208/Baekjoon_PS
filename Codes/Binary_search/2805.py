
class Alg:
    def solve(self):
        n, req = map(int, input().split())
        nums = list(map(int, input().split()))

        min_num, max_num = 0, max(nums)
        height = self.get_height(nums, req, min_num, max_num)
        print(height)

    def get_height(self, nums, req, min_num, max_num):
        mid_num = (min_num + max_num) // 2

        while min_num <= max_num:
            mid_num = (min_num + max_num) // 2
            get = 0
            for num in nums :
                if num > mid_num :
                    get += num - mid_num

            if get >= req :
                min_num = mid_num + 1
            else :
                max_num = mid_num - 1
                break
            

        return max

alg = Alg()
alg.solve()