#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <unordered_set>
#include <utility>

#define INF 1e9
#define up 1
#define down 2
#define left 3
#define right 4

using namespace std;

class Alg {
private:
    
    
public:
    void run();
    int board[1000][1000] = {0};
    int visit[1000][1000] = {0};
    int width, height;
    int cnt = 1;
    int num = 1;
    
private:
    void init_board();
    void solve();
    void dfs(int y, int x);
    void print_visit();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}


void Alg::run() {
    init_board();
    solve();
}

void Alg::init_board() {
    char data;
    
    cin >> height >> width;
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            cin >> data;
            switch (data) {
                case 'U': board[y][x] = up; break;
                case 'D': board[y][x] = down; break;
                case 'L': board[y][x] = left; break;
                case 'R': board[y][x] = right; break;
            }
        }
    }
}

void Alg::solve() {
    
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            if(visit[y][x]) { continue; }
            
            num++;
            dfs(y, x);
            //print_visit();
        }
    }
    cout << cnt - 1;
}

void Alg::dfs(int y, int x) {
    int next_x, next_y;
    
    int prev_y = y;
    int prev_x = x;
    
    do {
        visit[prev_y][prev_x] = num;
        switch (board[prev_y][prev_x]) {
            case up:
                next_x = prev_x;
                next_y = prev_y-1;
                break;
            case down:
                next_x = prev_x;
                next_y = prev_y+1;
                break;
            case left:
                next_x = prev_x-1;
                next_y = prev_y;
                break;
            case right:
                next_x = prev_x+1;
                next_y = prev_y;
                break;
        }
        
        if(visit[next_y][next_x] == num) { visit[prev_y][prev_x] = INF; cnt++; return; }
        
        prev_x = next_x;
        prev_y = next_y;
    } while (visit[next_y][next_x] == 0);
    
}

void Alg::print_visit() {
    cout << "\n";
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) { 
            if(visit[y][x] == INF) { cout << "*"; }
            else { cout << visit[y][x]; }
        }
        cout << "\n";
    }
}