#include <iostream>
#include <algorithm>
#include <limits>
#include <list>

#define null NULL

using namespace std;

class MainClass {
public:
    void run();
private:
    bool reached;
    int board[300][300];
    int size, rpt;
    int cnt;
    int y,x, end_y, end_x, tmp_x, tmp_y;;
    int next_x[8] = {1,2,2,1,-1,-2,-2,-1};  // 맨 위부터 시계방향
    int next_y[8] = {2,1,-1,-2,-2,-1,1,2};  // 맨 위부터 시계방향
    
    void init_board();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    reached = false;
    
    list<pair<int, int>> check_list, tmp_list;
    
    cin >> rpt;
    while(rpt--) {
        init_board();
        reached = false;
        cnt = 1;
        tmp_list.clear();
        check_list.clear();
        
        cin >> x >> y;
        tmp_list.push_back(make_pair(x, y));
        
        cin >> end_x >> end_y;
        
        while(!tmp_list.empty() and !reached) {
            check_list = tmp_list;
            tmp_list.clear();
            
            while(!check_list.empty() and !reached) {
                x = check_list.front().first;
                y = check_list.front().second;
                check_list.pop_front();
                
                if(y == end_y and x == end_x) { reached = true; break; }
                
                for(int i = 0; i < 8; i++) {
                    tmp_x = x + next_x[i];
                    tmp_y = y + next_y[i];
                    
                    if(tmp_y < 0 or size <= tmp_y or tmp_x < 0 or size <= tmp_x) { continue; }
                    if(board[tmp_y][tmp_x] != 0) { continue; }
                    
                    board[tmp_y][tmp_x] = cnt;
                    tmp_list.push_back(make_pair(tmp_x, tmp_y));
                    
                    if(tmp_y == end_y and tmp_x == end_x) { reached = true; break; }
                }
            }
            cnt++;
        }
        cout << board[end_y][end_x] << "\n";
    }
}

void MainClass::init_board() {
    cin >> size;
    
    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) { board[y][x] = 0; }
    }
}
