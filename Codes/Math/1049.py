
class Alg:
    def solve(self):
        req, buylist_size = map(int, input().split())
        min_pack_price, min_unit_price = self.get_cheapest(buylist_size)
        
        num_packs = req // 6
        num_units = req - 6 * num_packs

        # 전부 패키지로만 구매
        option1 = min_pack_price * (num_packs + 1)
        # 섞어서 구매
        option2 = min_pack_price * num_packs + min_unit_price * num_units
        # 전부 낱개로 구매
        option3 = min_unit_price * req
        
        coast = min(option1, option2, option3)
        print(coast)

    def get_cheapest(self, buylist_size):
        in_one = []
        indiv = []

        for _ in range(buylist_size):
            n1, n2 = map(int, input().split())
            in_one.append(n1)
            indiv.append(n2)

        return min(in_one), min(indiv)
    
alg = Alg()
alg.solve()