#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <unordered_set>
#include <utility>

using namespace std;

class Alg {
private:
    int num_of_ver, num_of_edge;
    vector<int> parent;
    
public:
    void run();
    
private:
    void init_graph();
    int find(int v);
    void union_set(int x, int y, int root_x, int root_y);
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}


void Alg::run() {
    int x, y;
    int ans = 0;
    
    init_graph();
    for(int i = 1; i <= num_of_edge; i++) {
        cin >> x >> y;
        
        int root_x = find(x);
        int root_y = find(y);
        
        if(ans == 0 and root_x == root_y) { ans = i; }
        else { union_set(x, y, root_x, root_y); }
    }
    
    cout << ans;
}

void Alg::init_graph() {
    cin >> num_of_ver >> num_of_edge;
    
    parent.resize(num_of_ver);
    for(int i = 0; i < num_of_ver; i++) { parent[i] = i; }
}

int Alg::find(int v) {
    if(parent[v] != v) { parent[v] = find(parent[v]); }
    return parent[v];
}

void Alg::union_set(int x, int y, int root_x, int root_y) {
    parent[root_y] = root_x;
}
