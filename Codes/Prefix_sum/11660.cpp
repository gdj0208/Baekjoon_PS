//
//  main.cpp
//  Learning
//
//  Created by 구동준 on 2022/10/02.
//

//#include "classtest.hpp"
//#include "DataStructure.h"

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
#define null NULL
#define MAX(a,b) a>b ? a:b

using namespace std;

class Alg{
private:
    int board[1025][1025] = {0};
    int board_size;
    int rpt;
    int x1, x2, y1, y2;
    
public:
    void run();
    void init_data();
    void solve();
    void make_sum_board();
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(NULL);
    
    Alg alg;
    alg.run();
}


void Alg::run() {
    
    init_data();
    make_sum_board();
    
    while(rpt--) {
        solve();
    }
    
}

void Alg::init_data() {
    
    cin >> board_size >> rpt;
    for(int y = 1; y <= board_size; y++) {
        for(int x = 1; x <= board_size; x++) { cin >> board[y][x];  }
    }
}

void Alg::solve() {
    cin >> y1 >> x1 >> y2 >> x2;
    cout << board[y1-1][x1- 1] + board[y2][x2] - board[y1 - 1][x2] - board[y2][x1 - 1] << "\n";
}

void Alg::make_sum_board() {
    for(int y = 1; y <= board_size; y++) {
        for(int x = 1; x <= board_size; x++) {
            board[y][x] += board[y][x-1];
        }
    }
    
    for(int x = 1; x <= board_size; x++) {
        for(int y = 1; y <= board_size; y++) {
            board[y][x] += board[y-1][x];
        }
    }
    
}
