#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>


#define INF 1e9

using namespace std;


class Alg {
private:
    int num_of_ver, num_of_edge;
    int *root;
    int sum_weight = 0;
    map<int, vector<pair<int, int>>> edges;
    
public:
    void run();
    
private:
    void solve();
    void init_graph();
    void init_ver();
    void init_edge();
    int Find(int x);
    bool Union_Find(int x, int y);
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}


void Alg::run() {
    init_graph();
    solve();
}

void Alg::init_graph() {
    cin >> num_of_ver >> num_of_edge;
    
    init_ver();
    init_edge();
}

void Alg::init_ver() {
    root = new int[num_of_ver + 1];
    for(int i = 0; i <= num_of_ver; i++) { root[i] = i; }
}

void Alg::init_edge() {
    int v1, v2, w;
    for(int i = 0; i < num_of_edge; i++) {
        cin >> v1 >> v2 >> w;
        edges[w].push_back(make_pair(v1, v2));
    }
}

void Alg::solve() {
    vector<int> ans_edge;
    int ans = 0;
    
    for(auto edge_list_by_weight : edges) {
        for(auto check_edge : edge_list_by_weight.second) {
            if(Union_Find(root[check_edge.first], root[check_edge.second])) { ans_edge.push_back(edge_list_by_weight.first); }
        }
    }
    
    for(int i = 0; i < ans_edge.size() - 1; i++) { ans += ans_edge[i]; }
    cout << ans;
}

int Alg::Find(int x) {
    if (root[x] == x) {
        return x;
    } else {
        return root[x] = Find(root[x]);
    }
}

bool Alg::Union_Find(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y) {
        return false;
    } else {
        root[y] = x;
        return true;
    }
}