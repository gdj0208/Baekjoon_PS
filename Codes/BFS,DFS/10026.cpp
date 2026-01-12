#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>

#define r 'R'
#define g 'G'
#define b 'B'

using namespace std;

class MainClass {
public:
    void run();
private:
    char photo[2][100][100];
    bool visited[2][100][100] = {0};
    int add_x[4] = {0,0,-1,1};     // 상하좌우
    int add_y[4] = {1,-1,0,0};
    int size;
    
    void init_graph();
    void init_visit();
    void print_graph();
    void count_area();
    void bfs(int y, int x, char color, bool is_week);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init_graph();
    //print_graph();
    count_area();
}

void MainClass::init_graph() {
    char data;
    
    cin >> size;
    
    for(int y = 0; y < size; y++) {
        getchar();
        for(int x = 0; x < size; x++) {
            scanf("%1c", &data);
            switch (data) {
                case r:
                    photo[0][y][x] = photo[1][y][x] = r;
                    break;
                case g:
                    photo[0][y][x] = g;
                    photo[1][y][x] = r;
                    break;
                case b:
                    photo[0][y][x] = photo[1][y][x] = b;
                    break;
            }
        }
    }
}

void MainClass::init_visit() {
    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) { visited[0][y][x] = visited[1][y][x] = 0; }
    }
}

void MainClass::print_graph() {
    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) { cout << photo[y][x]; }
        cout << "\n";
    }
}

void MainClass::count_area() {
    /*
     1. 모든 구역을 돌면서
     2. 방문하지 않은 구역이 있을 시 해당 지점에서 해당 색으로 bfs 실행
     3. 카운트++
     */
    int count = 0;
    int week_count = 0;
    //init_visit();
    
    for(int y = 0 ; y < size; y++) {
        for(int x = 0 ; x < size; x++) {
            if(visited[0][y][x] == false) {
                bfs(y, x, photo[0][y][x], 0);
                count++;
            }
            if(visited[1][y][x] == false) {
                bfs(y, x, photo[1][y][x], 1);
                week_count++;
            }
        }
    }
    
    cout << count << " " << week_count;
}

void MainClass::bfs(int y, int x, char color, bool is_week) {
    list<pair<int, int>> check_list, tmp;
    int now_y, now_x, next_x, next_y;
    
    tmp.push_back(make_pair(x, y));
    
    while(!tmp.empty()) {
        check_list = tmp;
        tmp.clear();
        
        while(!check_list.empty()) {
            now_x = check_list.front().first;
            now_y = check_list.front().second;
            check_list.pop_front();
            
            for(int i = 0; i < 4; i++) {
                next_x = now_x + add_x[i];
                next_y = now_y + add_y[i];
                
                if(next_x < 0 or size <= next_x or next_y < 0 or size <= next_y) { continue; }
                
                if(visited[is_week][next_y][next_x] == false and photo[is_week][next_y][next_x] == color) {
                    visited[is_week][next_y][next_x] = true;
                    tmp.push_back(make_pair(next_x, next_y));
                }
            }
        }
    }
}
