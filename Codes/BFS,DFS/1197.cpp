#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

class Alg {
private:
    map<int, vector<pair<int, int>>> Edges;
    int num_of_ver, num_of_edge;
    int *root;
    
public:
    void run();

private:
    void init_graph();
    int get_mst();
    bool does_all_vertics_in_same_root();
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Alg alg;
    alg.run();
}

void Alg::run() {
    init_graph();
    cout << get_mst();
}

void Alg::init_graph() {
    int v1, v2, weight;
    
    cin >> num_of_ver >> num_of_edge;
    
    root = new int[num_of_ver + 1];
    for(int i = 1; i <= num_of_ver; i++) { root[i] = i; }
    
    for(int i = 0; i < num_of_edge; i++) {
        cin >> v1 >> v2 >> weight;
        Edges[weight].push_back(make_pair(v1, v2));
    }
}

int Alg::get_mst() {
    int edge_cnt;
    int sum;
    int v1, v2;
    int smaller_root, bigger_root;
    
    sum = 0;
    edge_cnt = 0;
    
    while(does_all_vertics_in_same_root() == false) {
        for(auto [w, edges] : Edges) {
            for(auto edge : edges) {
                v1 = edge.first;
                v2 = edge.second;
                
                if(root[v1] == root[v2]) { continue; }
                
                smaller_root = root[v1] < root[v2] ? root[v1] : root[v2];
                bigger_root = root[v1] < root[v2] ? root[v2] : root[v1];
                
                for(int i = 1; i <= num_of_ver; i++) { root[i] = (root[i] == bigger_root) ? smaller_root : root[i]; }
                
                sum += w;
            }
        }
    }
    
    return sum;
}

bool Alg::does_all_vertics_in_same_root() {
    int r = root[1];
    for(int i = 2; i <= num_of_ver; i++) { if(r != root[i]) { return false; } }
    return true;
}
