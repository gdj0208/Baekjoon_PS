#include <iostream>
#include <queue>

#define space 0
#define wall 1
#define passed 2

using namespace std;

class MainClass {
public:
    void run();
private:
    int width, height;
    int maze[1000][1000];
    int len[2][1000][1000] = {0};
    int move_x[4] = {0, 0, -1, 1};   // 상 하 좌 우
    int move_y[4] = {-1, 1, 0, 0};   // 상 하 좌 우

    void bfs_break();
    void make_maze();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    make_maze();
    bfs_break();
    if (len[0][height - 1][width - 1] or len[1][height - 1][width - 1]) {
        if(len[0][height - 1][width - 1] == 0) { printf("%d", len[1][height - 1][width - 1]); }
        else if(len[1][height - 1][width - 1] == 0) { printf("%d", len[0][height - 1][width - 1]); }
        else { printf("%d", (len[0][height - 1][width - 1] < len[0][height - 1][width - 1]) ? len[0][height - 1][width - 1] : len[1][height - 1][width - 1]); }
    } else {
        printf("%d", -1);
    }
}

void MainClass::bfs_break() {
    queue<pair<pair<int, int>, pair<bool, int>>> q;
    q.push({{0, 0}, {false, 1}});

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        bool breaked = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        
        if(len[breaked][y][x] >= cnt) { continue; }
        
        len[breaked][y][x] = cnt;

        for (int i = 0; i < 4; i++) {
            int next_x = x + move_x[i];
            int next_y = y + move_y[i];

            if (0 <= next_x and next_x < width and
                0 <= next_y and next_y < height and
                maze[next_y][next_x] != passed and
                len[breaked][next_y][next_x] == 0) {
                if (maze[next_y][next_x] == space) {
                    q.push({{next_x, next_y}, {breaked, cnt + 1}});
                } else if (maze[next_y][next_x] == wall and !breaked) {
                    q.push({{next_x, next_y}, {true, cnt + 1}});
                }
            }
        }
    }
}

void MainClass::make_maze() {
    cin >> height >> width;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            scanf("%1d", &maze[y][x]);
        }
    }
}
