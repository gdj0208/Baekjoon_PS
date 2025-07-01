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
    int num_of_ver, num_of_edge;
    int start, end;
    vector<map<int, int>> Edges;
    
public:
    void run();
    void init_graph();
    void add_road();
    void solve();
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Alg alg;
    alg.run();
}


void Alg::run() {
    init_graph();
    solve();
}

void Alg::init_graph() {
    cin >> num_of_ver >> num_of_edge;
    Edges.resize(num_of_ver + 1);  // 벡터를 적절한 크기로 초기화
    add_road();
    cin >> start >> end;
}

void Alg::add_road() {
    for (int i = 0; i < num_of_edge; i++) {
        int S, E, T;
        cin >> S >> E >> T;
        
        if(Edges[S].find(E) == Edges[S].end() or
           (Edges[S].find(E) != Edges[S].end() and T < Edges[S][E])) { Edges[S][E] = T; }
    }
}

void Alg::solve() {
    queue<int> checkList;
    vector<int> dist(num_of_ver + 1);
    fill(dist.begin(), dist.end(), INF);
    
    dist[start] = 0;
    checkList.push(start);
    
    while(!checkList.empty()) {
        int s = checkList.front();
        checkList.pop();
        
        for(auto [e,w] : Edges[s]) {
            if(dist[s] != INF and dist[s] + w < dist[e]) {
                dist[e] = dist[s] + w;
                checkList.push(e);
            }
        }
    }
    
    cout << dist[end];
}
