#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>
#include <unordered_set>

#define INF 1e9

using namespace std;


class Alg {
private:
    unordered_set<int> *edge;
    int *ver_weight;
    int *ver_sum_weight;
    bool *ver_visit;
    int test_time;
    int num_of_ver, num_of_edge;
    int start_ver;
    
public:
    void run();
    
private:
    void get_num(int &num);
    void get_graph();
    void solve();
    void print_max();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}


void Alg::run() {
    get_num(test_time);
    while(test_time--) {
        get_num(num_of_ver); get_num(num_of_edge);
        get_graph();
        get_num(start_ver);
        solve();
        print_max();
    }
}

void Alg::get_num(int &num) { cin >> num; }

void Alg::get_graph() {
    int v1, v2;
    
    // 정점 가중치 초기화
    ver_weight = new int[num_of_ver + 1];
    ver_sum_weight = new int[num_of_ver + 1];
    for(int i = 1; i <= num_of_ver; i++) {
        cin >> ver_weight[i];
        ver_sum_weight[i] = ver_weight[i];
    }
    
    
    // 간선 초기화
    edge = new unordered_set<int>[num_of_ver + 1];
    for(int i = 1; i <= num_of_edge; i++) {
        cin >> v1 >> v2;
        edge[v2].insert(v1);
    }
}

void Alg::solve() {
    queue<int> search_list;
    int search_ver;
    
    // 정점 방문여부 초기화
    ver_visit = new bool[num_of_ver + 1];
    fill(ver_visit, ver_visit + num_of_ver + 1, false);
    
    // 시작점 설정
    search_list.push(start_ver);
    ver_visit[start_ver] = true;
    
    // 조사할 점을 대상으로 인접 점들의 총 제조 시간을 계산
    while(!search_list.empty()) {
        search_ver = search_list.front();
        search_list.pop();
        
        for(auto adj : edge[search_ver]) {
            if(ver_sum_weight[adj] < ver_weight[adj] + ver_sum_weight[search_ver]) {
                ver_sum_weight[adj] = ver_weight[adj] + ver_sum_weight[search_ver];
                search_list.push(adj);
                ver_visit[adj] = true;
            }
        }
    }
}

void Alg::print_max() {
    int max_num = 0;
    for(int i = 1; i <= num_of_ver; i++) {
        if( !ver_visit[i] ) { continue; }
        max_num = max(max_num, ver_sum_weight[i]);
        //cout << ver_sum_weight[i] << " ";
    }
    cout << max_num << "\n";
}
