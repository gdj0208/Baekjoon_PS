
UP = 0
RIGHT = 1
DOWN = 2
LEFT = 3

class Snake :
    def __init__(self) :
        self.bodys = [[1,1]]
        self.dir = RIGHT     # 0~3 : 상우하좌

class Game : 
    def __init__(self) :
        self.RUN = True
        self.snake = Snake()

        self.board_size = int(input())
        self.apples = self.get_apples()
        self.ops = self.get_ops()
        self.turn = 0

    def get_apples(self) :
        num_apple = int(input())
        apples = []
        for _ in range(num_apple) :
            y, x = map(int, input().split())
            apples.append([y, x])
        return apples
    
    def get_ops(self) : 
        num_op = int(input())
        opperation = []
        for _ in range(num_op) :
            inputs = input().split()
            opperation.append([int(inputs[0]), inputs[1]])
        return opperation
    
    def is_out_of_map(self, y, x) :
        return y < 1 or self.board_size < y or x < 1 or self.board_size < x

    def ate_itself(self, y, x) :
        return [y,x] in self.snake.bodys
    
    def ate_apple(self, y, x) :
        return [y,x] in self.apples

    def forward(self) :
        head = self.snake.bodys[-1]
        if self.snake.dir == UP :
            next_y = head[0]-1
            next_x = head[1]
        elif self.snake.dir == RIGHT :
            next_y = head[0]
            next_x = head[1]+1
        elif self.snake.dir == DOWN :
            next_y = head[0]+1
            next_x = head[1]
        elif self.snake.dir == LEFT :
            next_y = head[0]
            next_x = head[1]-1
        
        # 맵 밖으로 나가기
        if self.is_out_of_map(next_y, next_x) :
            return -1
        
        # 스스로 먺기
        if self.ate_itself(next_y, next_x) : 
            return -1

        self.snake.bodys.append([next_y, next_x])

        # 사과를 먹은 경우 사과 목록에서 해당 사과 제거
        if self.ate_apple(next_y, next_x) :
            self.apples.remove([next_y, next_x])
        else : # 사과를 먹지 못한 경우 꼬리 1칸 감소
            self.snake.bodys.pop(0)
            
    def change_dir(self) :
        if len(self.ops) == 0 :
            return 

        if self.ops[0][0] != self.turn :
            return
        
        _, next_dir = self.ops.pop(0)
        if next_dir == 'D' :
            self.snake.dir = (self.snake.dir + 1) % 4
        else :
            self.snake.dir = (self.snake.dir + 3) % 4

    def run_game(self) :
        while(self.RUN) :

            self.turn += 1

            if self.forward() == -1 :
                self.RUN = False
                break

            self.change_dir()

            """if len(self.apples) == 0:
                self.run = False
                break"""

        print(self.turn)

game = Game()
game.run_game()