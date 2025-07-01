#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
#define null NULL
#define space 0
#define cheeze 1
#define out 2

using namespace std;

class Alg{
private:
    int width, height;
    vector<vector<int>>board;
    int melting_time = 0;
    
public:
    void run();
    void set_board_size();
    void set_board_data();
    void init_board();
    void check_outter_space();
    void bfs(int x, int y);
    void erase_out(bool *cheeze_left);
    bool should_eraseable(int x, int y);
    void melt_the_cheeze();
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Alg alg;
    alg.run();
}


void Alg::run() {
    init_board();           // 보드판 정보 입력받기
    check_outter_space();   // 보드만 4개 모퉁이에서 bfs를 돌려 외부 공간을 탐색 (탐색하며 외부 공간을 2로 저장)
    melt_the_cheeze();      // 치즈 제거 작업
    
    cout << melting_time;
}

void Alg::init_board() {
    set_board_size();       // 보드판 크기 입력
    set_board_data();       // 보드판 정보 입력
}

void Alg::set_board_size() {
    cin >> height >> width;
    
    board.resize(height);
    for(int i = 0; i < height; i++) { board[i].resize(width); }
}

void Alg::set_board_data() {
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) { cin >> board[y][x]; }
    }
}

void Alg::check_outter_space() {
    
    /*  1. bfs 알고리즘을 통해 외부를 전부 표시한다.
        2. 맨 가장자리 4곳이 bfs 알고리즘의 시작점.    */
    
    // 가장자리 4곳 위치
    map<int, pair<int, int>> check_location;
    check_location[0] = make_pair(0, 0);
    check_location[1] = make_pair(width-1, 0);
    check_location[2] = make_pair(0, height-1);
    check_location[3] = make_pair(width-1, height-1);
    
    for(int i = 0; i < 4; i++) {
        int tmp_x = check_location[i].first;
        int tmp_y = check_location[i].second;
        
        if(board[tmp_y][tmp_x] == space) { bfs(tmp_x, tmp_y); }
    }
    
}

void Alg::bfs(int x, int y) {
    int next_x[4] = {0,0,-1,1};
    int next_y[4] = {-1,1,0,0};
    
    int tmp_x, tmp_y;
    
    queue<pair<int, int>> check_list;
    check_list.push(make_pair(x, y));
    
    while(!check_list.empty()) {
        auto [xp, yp] = check_list.front();
        board[yp][xp] = out;
        check_list.pop();
        
        for(int i = 0; i < 4; i++) {
            tmp_x = xp + next_x[i];
            tmp_y = yp + next_y[i];
            
            if(tmp_x < 0 or tmp_x >= width or tmp_y < 0 or tmp_y >= height) { continue; }
            if(board[tmp_y][tmp_x] == space) {
                board[tmp_y][tmp_x] = out;
                check_list.push(make_pair(tmp_x, tmp_y));
            }
        }
    }
    
}

void Alg::erase_out(bool *cheeze_left) {
    // 녹은 치즈의 위치 목록
    queue<pair<int, int>> space_list;
    
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            /*  1. 조사하는 공간이 치즈일 때만 작업
                2. 조사하는 공간이 치즈여도 외부 공간이 2 이하이면 작업 생략
                    -> 작업하지 않는 치즈가 있다 = 녹여야할 치즈가 남아있다.  */
            if(board[y][x] != cheeze) { continue; }
            if(should_eraseable(x, y) == false) { *cheeze_left = true; continue; }
            
            // 치즈 녹이기
            board[y][x] = space;
            space_list.push({x,y});
        }
    }
    
    // 빈 공간이 된 녹은 치즈의 위치에 대해 bfs로 외부 공간인지 조사
    while(!space_list.empty()) {
        auto [x,y] = space_list.front();
        space_list.pop();
        
        bfs(x, y);      // 외부 공간 조사
    }
}

bool Alg::should_eraseable(int x, int y) {
    int next_x[4] = {0,0,-1,1};
    int next_y[4] = {-1,1,0,0};
    int count = 0;
    int tmp_x, tmp_y;
    
    // 조사하는 공간에 대해 상하좌우 순으로 외부공간이 2개 이상인지 조사
    for(int i = 0; i < 4; i++) {
        tmp_x = x + next_x[i];
        tmp_y = y + next_y[i];
        
        if(tmp_x < 0 or tmp_x >= width or tmp_y < 0 or tmp_y >= height) { continue; }
        if(board[tmp_y][tmp_x] == 2) { count++; }
    }
    
    return count >= 2;
}

void Alg::melt_the_cheeze() {
    bool cheeze_left = true;
    
    // 치즈가 남아있는 동안 계속 녹인다.
    while (cheeze_left) {
        cheeze_left = false;
        erase_out(&cheeze_left);    // 치즈 지우기
        melting_time++;
    };
    
}
