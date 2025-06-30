#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>

#define wall '*'
#define non '.'
#define point 'C'
#define up 0
#define down 1
#define left 2
#define right 3

using namespace std;

class Alg {
private:
    int width, height;
    pair<int, int> start_point, end_point;
    int move_x[4] = {0,0,-1,1};
    int move_y[4] = {-1,1,0,0};
    bool has_init_start_point = false;
    char **map;
    bool **visit;
    
public:
    void run();
    
private:
    void init_graph();
    void find_path();
    bool has_reached_end_point(int y, int x);
    bool is_out_of_map(int y, int x);
    void print_trace();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    /*
     1. 그래프를 초기화합니다.
     2. 시작점에서부터 종점까지 탐색합니다.
        2.1. 탐색 방법은 다음과 같습니다.
            1) 탐색 점을 기준으로 가로, 세로로 벽에 닿을 때까지 모든 칸을 방문합니다.
            2) 방문한 칸들은 전부 탐색 목록에 넣습니다.
            3) 종점에 도달할 때까지 이를 반복합니다.
        -> 탐색 과정 중 방향을 바꾼 회수를 찾습니다.
     */
    init_graph();
    find_path();
}

void Alg::init_graph() {
    // 지도의 넓이 높이입니다.
    cin >> width >> height;
    
    // 지도를 초기화합니다.
    map = new char*[height];
    for(int y = 0; y < height; y++) { map[y] = new char[width]; }
    
    // 방문여부를 초기화합니다.
    visit = new bool*[height];
    for(int y = 0; y < height; y++) { visit[y] = new bool[width]; fill(&visit[y][0], &visit[y][width-1], false); }
    
    // 지도의 칸별로 공간, 벽, 시작점, 종점여부를 저장합니다.
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            cin >> map[y][x];
            if(map[y][x] == point) {
                if(has_init_start_point == true) { end_point.first = y; end_point.second = x; }
                else { start_point.first = y; start_point.second = x;  has_init_start_point = true;}
            }
        }
    }
}

void Alg::find_path() {
    // check_list는 이번에 조사할 정점들의 목록입니다.
    // tmp_list는 다음에 조사할 정점들의 목록입니다.
    list<pair<int, int>> check_list, tmp_list;
    
    int way_changed_time = -1;          // 방향 전환 횟수입니다.
    
    tmp_list.push_back({start_point.first, start_point.second});
    
    while(!tmp_list.empty()) {
        // 다음에 조사할 정점들의 목록을 이번에 조사할 정점들의 목록으로 바꿉니다.
        check_list = tmp_list;
        tmp_list.clear();
        
        // 방향 전환 횟수 1회 증가
        way_changed_time++;
        
        while(!check_list.empty()) {
            // 조사할 시작점의 위치입니다.
            int y = check_list.front().first;
            int x = check_list.front().second;
            check_list.pop_front();
            
            // 상하좌우 순으로 벽에 닿을 때까지 방문하는 칸들을 전부 다음에 조사할 목록에 넣습니다.
            for(int i = 0; i < 4; i++) {
                int next_y = y;
                int next_x = x;
                
                while(map[next_y][next_x] == non or(next_x == start_point.second and next_y == start_point.first)) {
                    next_x += move_x[i];
                    next_y += move_y[i];
                    
                    if(is_out_of_map(next_y, next_x) or map[next_y][next_x] == wall) { break; }         // 벽에 닿는지 검사합니다.
                    if(has_reached_end_point(next_y, next_x)) { cout << way_changed_time; return; }     // 종점에 도달했는지를 검사합니다.
                    if(visit[next_y][next_x] == true) { continue; }                                     // 이미 방문한 점들은 생략합니다.
                    
                    tmp_list.push_back({next_y, next_x});
                    visit[next_y][next_x] = true;
                }
            }
        }
    }
}

bool Alg::has_reached_end_point(int y, int x) { return y == end_point.first and x == end_point.second; }

bool Alg::is_out_of_map(int y, int x) {
    if(y < 0 or height <= y) { return true; }
    if(x < 0 or width <= x) { return true; }
    return false;
}

void Alg::print_trace() {
    cout << "\n";
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            if(map[y][x] == non and visit[y][x]) {cout << "@";}
            else cout << map[y][x];
        }
        cout << "\n";
    }
}
