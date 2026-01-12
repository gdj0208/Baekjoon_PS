#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;


class Alg {
private:
    int num_of_edge, len;
    vector<pair<int, int>> edges;
    
    void get_edge();
    void get_ans();
    static bool Compare(const pair<int,int>& a, const pair<int, int>& b);
    
public:
    void run();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    get_edge();
    sort(edges.begin(), edges.end(), Compare);
    get_ans();
}

void Alg::get_edge() {
    int n1, n2;
    
    cin >> num_of_edge;
    for(int i = 0; i < num_of_edge; i++) {
        cin >> n1 >> n2;
        
        // 언제나 시작점이 앞에 오게 전환
        if(n1 > n2) {
            int tmp = n1;
            n1 = n2;
            n2 = tmp;
        }
        
        edges.push_back({n1, n2});
    }
    
    cin >> len;
}

void Alg::get_ans() {
    int max = 0;                    // 최대 간선의 수
    priority_queue<int, vector<int>, greater<int>> lists;    // 조사하는 간선 목록
    
    for(int i = 0; i < edges.size(); i++) {
        auto edge = edges[i];
        
        // 각 간선들을 조사 목록 안에 넣음
        lists.push(edge.first);
        
        // 조사 목록 중 가장 먼저 들어온 간선의 시작점과 이번에 들어가는 간선의 종점과의 거리가 제한 범위보다 멀면 조사 목록에서 제외
        while(!lists.empty() and lists.top() < edge.second - len) {
            lists.pop();
        }
        
        // 조사 목록 안에 있는 최대 간선의 수 저장
        max = (lists.size() > max) ? lists.size() : max;
    }
    
    cout << max;
}

bool Alg::Compare(const pair<int,int>& a, const pair<int, int>& b) {
    if(a.second == b.second) { return a.first < b.first; }
    return a.second < b.second;
}
