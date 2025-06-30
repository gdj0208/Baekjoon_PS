#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

#define INF 1e8

using namespace std;

class Alg {
public:
    void run();
    
private:
    int map[1001][1001];
    int visit[1001][1001] = {0};
    int width, height, group_num;
    int move_x[4] = {-1,1,0,0};
    int move_y[4] = {0,0,-1,1};
    vector<int> group_size;
    
    void init_map();
    void get_groups();
    int bfs(int x, int y, int group_idx);
    bool is_out_of_map(int x, int y);
    void print_ans();
    int get_moveable_area(int x, int y);
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
    get_groups();
    print_ans();
}

void Alg::init_map() {
    string str;
    cin >> height >> width;
    
    for(int y = 0; y < height; y++) {
        cin >> str;
        for(int x = 0; x < width; x++) { map[y][x] = str[x]-'0'; }
    }
}

int Alg::bfs(int x, int y, int group_idx) {
    queue<pair<int, int>> lists; // x, y,
    int next_x, next_y;
    int cur_x, cur_y, z;
    int cnt = 0;
    
    lists.push({x,y});
    visit[y][x] = group_idx;
    
    while(!lists.empty()) {
        cur_x = lists.front().first;
        cur_y = lists.front().second;
        cnt++;
        lists.pop();
        
        for(int i = 0; i < 4; i++) {
            next_x = cur_x + move_x[i];
            next_y = cur_y + move_y[i];
            
            // 맵을 나갔는지 여부
            if(is_out_of_map(next_x, next_y)) { continue; }
            
            // 벽에 도달한 경우
            if(map[next_y][next_x]) { continue; }
            
            // 다른 그룹인 경우
            if(visit[next_y][next_x] != 0) { continue; }
            
            visit[next_y][next_x] = group_idx;
            lists.push({next_x, next_y});
        }
    }
    
    return cnt;
}

bool Alg::is_out_of_map(int x, int y) {
    return x < 0 or width <= x or y < 0 or height <= y;
}

void Alg::get_groups() {
    group_num = 1;
    group_size.push_back(0);
    
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            if(map[y][x] == 0 and visit[y][x] == 0) {
                group_size.push_back(bfs(x, y, group_num++));
            }
        }
    }
}

void Alg::print_ans() {
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            if(map[y][x] != 0) { map[y][x] = get_moveable_area(x, y) % 10; }
        }
    }
    
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) { cout << map[y][x]; }
        cout << "\n";
    }
}

int Alg::get_moveable_area(int x, int y) {
    int cnt = 1;
    int next_x, next_y;
    int group;
    set<int> groups;
    
    for(int i = 0; i < 4; i++) {
        next_x = x + move_x[i];
        next_y = y + move_y[i];
        
        if(is_out_of_map(next_x, next_y)) { continue; }
        if(map[next_y][next_x] != 0) { continue; }
        
        group = visit[next_y][next_x];
        
        // 이미 방문한 그룹은 생략
        if(groups.find(group) != groups.end()) { continue; }
        
        groups.insert(group);
        cnt += group_size[group];
    }
    
    return cnt;
}


/*
 3 3
 000
 010
 000
 9
 
 4 5
 1 1 0 0 1
 
 */
