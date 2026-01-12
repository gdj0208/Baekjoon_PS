#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>

#define INF -1
using namespace std;

class Alg {
private:
    int num_of_ver;
    int *dist;
    vector<unordered_map<int, int>> edge;
    
public:
    void run();
    
private:
    void init_graph();
    void print_max_dist();
    int get_most_far_ver(int v);
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
     1. 그래프 초기화
     2. 인접 정점이 1개인 정점들을 대상으로 모든 정점의 거리를 구함
        -> 가장 먼 정점의 거리를 저장
     3. 2에서 나온 거리 중 가장 긴 거리를 출력
     */
    init_graph();
    print_max_dist();
}

void Alg::init_graph() {
    int v1, v2, weight;
    
    cin >> num_of_ver;
    
    dist = new int[num_of_ver + 1];
    edge.resize(num_of_ver + 1);
    
    for(int i = 0; i < num_of_ver; i++) {
        cin >> v1;
        
        while(true) {
            cin >> v2;
            if(v2 == -1) { break; }
            
            cin >> weight;
            edge[v1][v2] = weight;
        }
    }
}

void Alg::print_max_dist() {
    int v1, v2;
    v1 = get_most_far_ver(1);
    v2 = get_most_far_ver(v1);
    cout << dist[v2];
}

int Alg::get_most_far_ver(int v) {
    int max_dist = 0;
    int max_dist_loc = -1;
    
    fill(dist, dist + num_of_ver + 1, -1);
    dist[v] = 0;
    
    queue<pair<int, int>>check_list;
    check_list.push({dist[v], v});
    
    while(!check_list.empty()) {
        int cur_dist = check_list.front().first;
        int cur_loc = check_list.front().second;
        check_list.pop();
        
        for(auto adj : edge[cur_loc]) {
            int next_loc = adj.first;
            int next_weight = dist[cur_loc] + adj.second;
            
            if(dist[next_loc] == -1 or dist[next_loc] > next_weight) {
                dist[next_loc] = next_weight;
                check_list.push({dist[next_loc], next_loc});
            }
        }
        if(edge[cur_loc].size() == 1 and max_dist < dist[cur_loc]) {
            max_dist = dist[cur_loc];
            max_dist_loc = cur_loc;
        }
    }
    
    return max_dist_loc;
}
