class Alg :
    def solve(self):
        num_holes, num_usages = map(int, input().split())
        usage_order = list(map(int, input().split()))
        plugs = []
        count = 0

        for i in range(num_usages):

            # 가전제품이 이미 플러그에 연결되어있는지를 확인
            if usage_order[i] in plugs :
                continue

            # 연결할 플러그 구멍이 있는 경우 연결하고 끝냄
            if len(plugs) < num_holes :
                plugs.append(usage_order[i])
            else :
                # 연결할 플러그 구멍이 없는 경우

                # 가장 오랫동안 안 쓸 플러그 찾기
                change_plug_num = self.find_longest_use_plug(num_holes, i, num_usages, usage_order, plugs)

                # 가장 오랫동안 안 쓸 플러그에 새로 사용할 가전제품 연결
                plugs[change_plug_num] = usage_order[i]

                # 변경 횟수 추가
                count += 1

        print(count)

    def find_longest_use_plug(self, num_holes, cur_index, num_usages, usage_order, plugs) :
        next_turn = [float('inf') for _ in range(num_holes)]

        for n in range(cur_index, num_usages) :
            for i in range(len(plugs)) :
                if plugs[i] == usage_order[n] :
                    next_turn[i] = min(next_turn[i],n)
        
        max_turn = 0
        max_idx = 0

        for i in range(len(plugs)) :
            if max_turn < next_turn[i] :
                max_idx = i
                max_turn = next_turn[i]

        return max_idx
        
alg = Alg()
alg.solve()