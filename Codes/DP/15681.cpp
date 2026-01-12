#include <iostream>
#include <set>
#include <list>

using namespace std;

class Alg {
private:
    set<int>* Edge;
    int* rank;
    int* size;
    int num_of_ver, root, rpt;
    
public:
    void run();

private:
    void init_graph();
    void init_rank();
    void init_size();
    int get_size(int node);
    void print_rank();
    void print_size();
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
    init_rank();
    //print_rank();
    init_size();
    print_size();
}

void Alg::init_graph() {
    int v1, v2;
    cin >> num_of_ver >> root >> rpt;
    
    Edge = new set<int>[num_of_ver + 1];
    
    for(int i = 0; i < num_of_ver - 1; i++) {
        cin >> v1 >> v2;
        Edge[v1].insert(v2);
        Edge[v2].insert(v1);
    }
}

void Alg::init_rank() {
    list<int> check_list;
    int check_ver;
    
    rank = new int[num_of_ver + 1];
    fill(rank, rank + num_of_ver, 0);
    
    check_list.push_back(root);
    while(!check_list.empty()) {
        check_ver = check_list.front();
        check_list.pop_front();
        
        for(auto adj : Edge[check_ver]) {
            if(adj == root) { continue; }
            if(rank[adj] != 0 or rank[adj] > rank[check_ver])  { continue; }
            
            rank[adj] = rank[check_ver] + 1;
            check_list.push_back(adj);
        }
    }
}

void Alg::print_rank() {
    for(int ver = 1; ver <= num_of_ver; ver++) {
        cout << ver << " : " << rank[ver] << "\n";
    }
}

void Alg::init_size() {
    size = new int[num_of_ver + 1];
    fill(size, size + num_of_ver, 0);
    size[root] = get_size(root);
}

int Alg::get_size(int node) {
    int cnt = 0;
    
    for(auto adj : Edge[node]) {
        if(rank[adj] > rank[node]) {
            size[adj] = get_size(adj);
            cnt += size[adj];
        }
    }
    
    return cnt + 1;
}

void Alg::print_size() {
    int node;
    while(rpt--) {
        cin >> node;
        cout << size[node] << "\n";
    }
}
