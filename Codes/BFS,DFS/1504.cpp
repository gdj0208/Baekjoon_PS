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
    int num_of_ver, num_of_edge;
    int must_pass_v1, must_pass_v2;
    vector<unordered_map<int, int>> edge;
    
public:
    void run();
    
private:
    void init_graph();
    tuple<int, int, int> get_dist(int num);   // num번 점에서 부터 1,n, v번 점까지의 거리
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
     2. 필수로 지나는 점별로 1,n번 정점까지의 거리를 구함
     3. (필점1->1,n번 점 거리 + 필점2->1,n번 점 거리 + 필점1->필점2)가 최소인 거리 출력
     */
    init_graph();
    tuple<int, int, int>dist_from_v1 = get_dist(must_pass_v1);
    tuple<int, int, int>dist_from_v2 = get_dist(must_pass_v2);
    
    //cout << dist_from_v1.first << " " << dist_from_v1.second << "\n";
    //cout << dist_from_v2.first << " " << dist_from_v2.second << "\n";
    
    /*
     경로가 없는 경우
     1. 1,n 정점이 v1,v2에 둘 다 안닿음
     (v1->1 == INF and v2->1 == INF) or (v1->n == INF and v2->n == INF)
     2. v1, v2정점이 1,n에 둘 다 안닿음
     (v1->1 == INF and v1->n == INF) or (v2->1 == INF and v2->n == INF)
     3. v1에서 v2가 안닿음
     v2->v2 == INF
     */
    if((get<0>(dist_from_v1) == INF and get<0>(dist_from_v2) == INF) or (get<1>(dist_from_v1) == INF and get<1>(dist_from_v2) == INF)
       or (get<0>(dist_from_v1) == INF and get<1>(dist_from_v1) == INF) or (get<0>(dist_from_v2) == INF and get<1>(dist_from_v2) == INF)
       or (get<1>(dist_from_v1) == INF))
    { cout << -1; }
    else {
        int dist1 = get<0>(dist_from_v1) + get<1>(dist_from_v2) + get<2>(dist_from_v1);
        int dist2 = get<1>(dist_from_v1) + get<0>(dist_from_v2) + get<2>(dist_from_v1);
        int min_dist = (dist1 < dist2) ? dist1 : dist2;
        
        cout << min_dist;
    }
}

void Alg::init_graph() {
    int v1, v2, weight;
    
    cin >> num_of_ver >> num_of_edge;
    edge.resize(num_of_ver + 1);
    
    for(int i = 0; i < num_of_edge; i++) {
        cin >> v1 >> v2 >> weight;
        edge[v1][v2] = edge[v2][v1] = weight;
    }
    
    cin >> must_pass_v1 >> must_pass_v2;
}

tuple<int, int, int>Alg::get_dist(int num) {
    int dist[num_of_ver + 1];
    fill(dist, dist + num_of_ver + 1, INF);
    
    queue<pair<int, int>>check_list;
    
    dist[num] = 0;
    check_list.push({0, num});
    
    while(!check_list.empty()) {
        int cur_dist = check_list.front().first;
        int cur_loc = check_list.front().second;
        check_list.pop();
        
        for(auto adj : edge[cur_loc]) {
            int next_loc = adj.first;
            int next_dist = adj.second + cur_dist;
            
            if(dist[next_loc] == INF or dist[next_loc] > next_dist) {
                dist[next_loc] = next_dist;
                check_list.push({dist[next_loc], next_loc});
            }
        }
    }
    
    int dv = (num == must_pass_v1) ? dist[must_pass_v2] : dist[must_pass_v1];
    
    return { dist[1], dist[num_of_ver], dv};
}
