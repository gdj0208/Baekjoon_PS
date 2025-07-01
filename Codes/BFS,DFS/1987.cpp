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

using namespace std;

const int INF = 1e11;

class Alg{
private:
    int width, height;
    char board[20][20];
    int dist[20][20];
    int next_x[4] = {0 ,0 ,-1 ,1};
    int next_y[4] = {-1 , 1, 0, 0};
    int max_dist = 1;
    bool visited[26] = {0};
public:
    void run();
    void init_graph();
    void dfs(int xp, int yp);
    void print_dist();
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Alg alg;
    alg.run();
}


void Alg::run() {
    init_graph();
    dist[0][0] = 1;
    visited[board[0][0] - 'A'] = true;
    dfs(0,0);
    //print_dist();
    cout << max_dist;
}

void Alg::init_graph() {
    cin >> height >> width;
    
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) { 
            cin >> board[y][x];
            dist[y][x] = INF;
        }
    }
}

void Alg::dfs(int xp, int yp) {
    int x = xp;
    int y = yp;
    char data;
    
    data = board[y][x] - 'A';
    
    for(int i = 0; i < 4; i++) {
        int tmp_x = x + next_x[i];
        int tmp_y = y + next_y[i];
        data = board[tmp_y][tmp_x] - 'A';
        
        if(tmp_x < 0 or tmp_x >= width or tmp_y < 0 or tmp_y >= height) { continue; }
        if(visited[data] == true) { continue; }
        if(dist[y][x] != INF and dist[tmp_y][tmp_x] <= dist[y][x] + 1)  { continue; }
        
        if(visited[data] == true) { return; }
        visited[data] = true;
        
        dist[tmp_y][tmp_x] = dist[y][x] + 1;
        max_dist = (dist[tmp_y][tmp_x] > max_dist) ? dist[tmp_y][tmp_x] : max_dist;
        
        dfs(tmp_x, tmp_y);
        
        dist[tmp_y][tmp_x] = INF;
        visited[data] = false;
    }
}

void Alg::print_dist() {
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            cout << dist[y][x] << " ";
        }
        cout << "\n";
    }
}
