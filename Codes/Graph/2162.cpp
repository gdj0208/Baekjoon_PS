#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

#define x first
#define y second
#define INF 1e8

using namespace std;

class Alg {
public:
    void run();
    
private:
    vector<int> edge_group;
    vector<int> group_size;
    vector<pair<pair<int, int>, pair<int, int>>> edges;
    pair<int, int> v1, v2;
    int num_of_edge;
    
    bool do_edges_touched(pair<pair<int, int>, pair<int, int>>, pair<pair<int, int>, pair<int, int>>);
    int ccw(pair<int, int>v1, pair<int, int>v2, pair<int, int>v3);
    bool is_overlapping(pair<pair<int, int>, pair<int, int>> e1, pair<pair<int, int>, pair<int, int>>e2);
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    
    cin >> num_of_edge;
    
    for(int i = 0; i < num_of_edge; i++) { edge_group.push_back(i); }
    group_size.resize(num_of_edge, 1);
    
    for(int i = 0; i < num_of_edge; i++) {
        cin >> v1.x >> v1.y >> v2.x >> v2.y;
        pair<pair<int, int>, pair<int, int>> newEdge = {{v1.x, v1.y}, {v2.x, v2.y}};
        
        
        for(int index = 0; index < edges.size(); index++) {
            // edge와 newEdge가 닿는가?
            if(do_edges_touched(edges[index], newEdge)) {
                int parent = edge_group[index];
                
                // 닿을 시 edge의 그룹명을 공유하는 모든 edge들의 그룹명을 newEdge로 수정
                for(int j = 0; j < i; j++) {
                    if(edge_group[j] == parent) { edge_group[j] = i; }
                }
            }
        }
        edges.push_back(newEdge);
    }
    
    
    map<int, int> group_num_size;
    int max = 0;
    for(int i = 0; i < num_of_edge; i++) {
        // 없는 경우
        if(group_num_size.find(edge_group[i]) == group_num_size.end()) { group_num_size[edge_group[i]] = 1; }
        else { group_num_size[edge_group[i]]++; }
        
        if(max < group_num_size[edge_group[i]]) { max = group_num_size[edge_group[i]]; }
    }
    cout << group_num_size.size() << endl << max;
}

bool Alg::do_edges_touched(pair<pair<int, int>, pair<int, int>> e1, pair<pair<int, int>, pair<int, int>>e2) {
    int n1 = ccw(e1.first, e1.second, e2.first) * ccw(e1.first, e1.second, e2.second);
    int n2 = ccw(e2.first, e2.second, e1.first) * ccw(e2.first, e2.second, e1.second);
    
    if(n1 == 0 and n2 == 0) { return is_overlapping(e1, e2); }
    return n1 <= 0 and n2 <= 0;
}

int Alg::ccw(pair<int, int>v1, pair<int, int>v2, pair<int, int>v3) {
    long long cross = (v2.x - v1.x) * (v3.y - v1.y) - (v2.y - v1.y) * (v3.x - v1.x);
    if (cross > 0) return 1;      // 반시계 방향
    else if (cross < 0) return -1; // 시계 방향
    else return 0;                // 일직선 상
}

bool Alg::is_overlapping(pair<pair<int, int>, pair<int, int>> e1, pair<pair<int, int>, pair<int, int>>e2) {
    if (max(e1.first.x, e1.second.x) >= min(e2.first.x, e2.second.x) && max(e2.first.x, e2.second.x) >= min(e1.first.x, e1.second.x) &&
        max(e1.first.y, e1.second.y) >= min(e2.first.y, e2.second.y) && max(e2.first.y, e2.second.y) >= min(e1.first.y, e1.second.y)) {
        return true;
    }
    return false;
}
