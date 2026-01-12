#include <iostream>
#include <list>

using namespace std;

class Alg {
private:
    int board[1001][1001];
    int dist[1001][1001] = {0};
    int width, height;
    int end_x, end_y;
    
public:
    void run();

private:
    void init_board();
    void get_dist();
    void print_board();
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Alg alg;
    alg.run();
}

void Alg::run() {
    init_board();
    get_dist();
    print_board();
}

void Alg::init_board() {
    int data;
    
    cin >> height >> width;
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            cin >> data;
            board[y][x] = data;
            
            if(data == 2) { end_x = x; end_y = y; }
        }
    }
}

void Alg::get_dist() {
    int x, y, next_x, next_y;
    int vec_x[4] = {0,0,-1,1};
    int vec_y[4] = {-1,1,0,0};
    list<pair<int, int>> check_list, tmp_list;

    
    tmp_list.push_back(make_pair(end_y, end_x));
    
    while(!tmp_list.empty()) {
        
        check_list = tmp_list;
        tmp_list.clear();
        
        while(!check_list.empty()) {
            y = check_list.front().first;
            x = check_list.front().second;
            check_list.pop_front();
            
            for(int i = 0; i < 4; i++) {
                next_x = x + vec_x[i];
                next_y = y + vec_y[i];
                
                if(next_x == end_x and next_y == end_y) { continue; }
                if(next_x < 0 or width <= next_x or next_y < 0 or height <= next_y) { continue; }
                if(board[next_y][next_x] == 0) { continue; }
                if(dist[next_y][next_x] != 0 and dist[next_y][next_x] <= dist[y][x] + 1) { continue; }
                
                dist[next_y][next_x] = dist[y][x] + 1;
                tmp_list.push_back(make_pair(next_y, next_x));
            }
        }
    }
}

void Alg::print_board() {
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) { 
            if(board[y][x] == 1 and dist[y][x] == 0) { cout << -1 << " "; }
            else { cout << dist[y][x] << " "; }
        }
        cout << "\n";
    }
}
