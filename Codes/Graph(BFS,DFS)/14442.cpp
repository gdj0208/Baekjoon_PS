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
    int get_max_dist();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    //int dist;
    
    init_map();
    bfs();
    
    cout << dist;
    
    //dist = get_max_dist();
    //if(dist == INF) { cout << -1; }
    //else { cout << dist; }
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
    queue<tuple<int, int, int>> lists; // x, y, z
    int next_x, next_y;
    int x, y, z;
    
    if(width == 1 and height == 1) { dist = 1; return; }
    
    lists.push({0,0,0});
    visit[0][0][0] = 1;
    
    while(!lists.empty()) {
        x = get<0>(lists.front());
        y = get<1>(lists.front());
        z = get<2>(lists.front());
        lists.pop();
        
        for(int i = 0; i < 4; i++) {
            next_x = x + move_x[i];
            next_y = y + move_y[i];
            
            // 맵을 나갔는지 여부
            if(is_out_of_map(next_x, next_y)) { continue; }
            
            if(next_y == height-1 and next_x == width-1) { dist = visit[z][y][x] + 1; return; }
            
            // 벽에 도달한 경우
            if(map[next_y][next_x]) {
                if(z >= breakable) { continue; }
                if(visit[z+1][next_y][next_x] != 0) { continue; }
                
                visit[z+1][next_y][next_x] = visit[z][y][x] + 1;
                lists.push({next_x, next_y, z + 1});
            }
            
            // 빈칸인 경우
            else {
                if(visit[z][next_y][next_x] != 0) { continue; }
                visit[z][next_y][next_x] = visit[z][y][x] + 1;
                lists.push({next_x, next_y, z});
            }
        }
    }
}

bool Alg::is_out_of_map(int x, int y) {
    return x < 0 or width <= x or y < 0 or height <= y;
}

int Alg::get_max_dist() {
    int max_val = INF;
    for(int z = 0; z <= breakable; z++) {
        if(visit[z][height-1][width-1] != 0) { max_val = min(max_val, visit[z][height-1][width-1]); }
    }
    return max_val;
}
