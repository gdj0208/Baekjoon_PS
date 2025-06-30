#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1e8

using namespace std;

class Alg {
public:
    void run();
    
private:
    int map[1001][1001];
    int visit[11][1001][1001] = {0};
    int width, height, breakable;
    int move_x[4] = {-1,1,0,0};
    int move_y[4] = {0,0,-1,1};
    int dist = -1;
    
    void init_map();
    void bfs();
    bool is_out_of_map(int x, int y);
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    
    init_map();
    bfs();
    cout << dist;
}

void Alg::init_map() {
    string str;
    cin >> height >> width >> breakable;
    
    for(int y = 0; y < height; y++) {
        cin >> str;
        for(int x = 0; x < width; x++) { map[y][x] = str[x]-'0'; }
    }
}

void Alg::bfs() {
    queue<tuple<int, int, int, bool, bool>> lists; // x, y, z
    int next_x, next_y;
    int x, y, z;
    bool is_day, stay;
    bool reached = false;
    
    if(width == 1 and height == 1) { dist = 1; return; }
    
    lists.push({0,0,0,1,0});
    visit[0][0][0] = 1;
    
    while(!lists.empty()) {
        x = get<0>(lists.front());
        y = get<1>(lists.front());
        z = get<2>(lists.front());
        is_day = get<3>(lists.front());
        stay = get<4>(lists.front());
        lists.pop();
        
        for(int i = 0; i < 4; i++) {
            next_x = x + move_x[i];
            next_y = y + move_y[i];
            
            // 맵을 나갔는지 여부
            if(is_out_of_map(next_x, next_y)) { continue; }
            
            if(next_y == height-1 and next_x == width-1) {
                //if(dist == -1) { dist = visit[z][y][x] + 1; }
                //else { dist = min(dist, visit[z][y][x] + 1); }
                //reached = true;
                dist = visit[z][y][x] + 1;
                return;
            }
            
            // 벽에 도달한 경우
            if(map[next_y][next_x]) {
                if(z >= breakable) { continue; }
                if(visit[z+1][next_y][next_x] != 0) { continue; }
                
                if(is_day) {
                    // 낮일 경우 부수고 들어감
                    visit[z+1][next_y][next_x] = visit[z][y][x] + 1 + stay;
                    lists.push({next_x, next_y, z + 1, !is_day, false});
                }
                else {
                    lists.push({x, y, z, !is_day, true});
                }
            }
            
            // 빈칸인 경우
            else {
                if(visit[z][next_y][next_x] != 0) { continue; }
                visit[z][next_y][next_x] = visit[z][y][x] + 1;
                lists.push({next_x, next_y, z, !is_day, false});
            }
        }
    }
}

bool Alg::is_out_of_map(int x, int y) {
    return x < 0 or width <= x or y < 0 or height <= y;
}
