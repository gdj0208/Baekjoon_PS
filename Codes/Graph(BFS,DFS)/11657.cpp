#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>

#define INF 1e8
using namespace std;


class Alg {
private:
    int num_of_ver, num_of_edge;
    long dist[501];
    vector<pair<int, int>> Edge[501];
    
public:
    void run();
    
private:
    void init_graph();
    void get_dist();
    void print_dist();
    bool have_neg_cycle();
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
     2. 벨만-포드 알고리즘을 통해 각 정점별 시작점과의 거리를 구한 후 음의 싸이클을 탐지하여 답을 출력합니다.
     */
    
    init_graph();   // 그래프 초기화
    get_dist();     // 각 정점별로 시작점과의 거리를 구합니다.
    
    // 음의 싸이클 탐지여부에 따라 답을 출력합니다.
    if(have_neg_cycle()) { cout << -1; }
    else { print_dist(); }
}

void Alg::init_graph() {
    int v1, v2, w;      // 시작점, 종점, 가중치
    
    // 정점의 수와 간선의 수를 입력받습니다.
    cin >> num_of_ver >> num_of_edge;
    
    // 간선들의 정보들을 입력받습니다.
    for(int i = 0;i < num_of_edge; i++) {
        cin >> v1 >> v2 >> w;
        Edge[v1].push_back({v2, w});
    }
}

void Alg::get_dist() {
    
    // 시작점을 제외한 모든 정점의 거리를 무한(1e8)로 초기화 합니다.
    fill(dist, &dist[num_of_ver + 1], INF);
    dist[1] = 0;
    
    // 아래는 벨만-포드 알고리즘에서 정점별 시작점과의 거리를 구하는 알고리즘입니다.
    for(int i = 0; i < num_of_ver - 1; i++) {
        for(int sp = 1; sp <= num_of_ver; sp++) {
            for(auto edge : Edge[sp]) {
                if(dist[sp] != INF and dist[edge.first] > dist[sp] + edge.second) { dist[edge.first] = dist[sp] + edge.second; }
            }
        }
    }
}

bool Alg::have_neg_cycle() {
    // 아래는 벨만-포드 알고리즘에서 음의 싸이클을 탐지하는 알고리즘입니다.
    for(int sp = 1; sp <= num_of_ver; sp++) {
        for(auto edge : Edge[sp]) {
            
            // 어느 한 정점의 시작점과의 거리가 줄어들 시 음의 싸이클이 있다는 뜻입니다.
            if(dist[sp] != INF and dist[edge.first] > dist[sp] + edge.second) { return true; }
        }
    }
    
    // 음의 싸이클이 탐지되지 않을 경우
    return false;
}

void Alg::print_dist() {
    for(int i = 2; i <= num_of_ver; i++) {
        if(dist[i] == INF) { cout << -1 << "\n"; }
        else { cout << dist[i] << "\n"; }
    }
}
