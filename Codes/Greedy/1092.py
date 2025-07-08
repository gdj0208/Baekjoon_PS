
class Alg :
    def solve(self):
        cranes = self.get_arrs()
        cargoes = self.get_arrs()

        cranes.sort(reverse=True)
        cargoes.sort(reverse=True)

        print(self.get_turns(cranes, cargoes))

    def get_arrs(self) :
        size = int(input())
        arr = list(map(int, input().split()))
                   
        return arr
    
    def get_turns(self, cranes, cargoes):
        from collections import deque

        cargoes = deque(cargoes)  # pop(0)보다 효율적인 구조
        positions = [0] * len(cranes)  # 각 크레인이 탐색할 위치 인덱스
        assigned = [False] * len(cargoes)  # 각 화물이 옮겨졌는지 표시
        count = 0
        moved = 0  # 전체 옮긴 화물 수
        check = False # 화물이 1개라도 옮겨졌는지 확인하는 변수

        # 다 옮길 때 까지 반복
        while moved < len(cargoes):
            idx = 0  # 현재 크레인 번호
            check = False

            # 각 화물별로 크레인으로 옮길 수 있는지 확인
            for i in range(len(cargoes)):

                # 모든 크레인이 1회씩 옮겼다. -> 처음부터 다시 시작
                if idx >= len(cranes):
                    break

                # 할당되지 않은 옮길 수 있는 화물 옮기기
                if not assigned[i] and cranes[idx] >= cargoes[i]:
                    assigned[i] = True
                    idx += 1
                    moved += 1
                    check = True

            # 화물이 옮겨지지 않았다면 더 이상 옮길 수 없다는 것
            if not check:
                return -1
            
            count += 1
        return count
    
alg = Alg()
alg.solve()