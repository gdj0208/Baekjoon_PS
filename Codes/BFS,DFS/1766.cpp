#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

class Alg {
private:
    unordered_set<int> *parent;
    unordered_set<int> *child;
    set<int> check_list;
    int num_of_ver, num_of_edge;
    
public:
    void run();
    
private:
    void init_graph();
    void print_in_ord();
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
    print_in_ord();
}

void Alg::init_graph() {
    int in, out;
    
    cin >> num_of_ver >> num_of_edge;
    parent = new unordered_set<int>[num_of_ver + 1];
    child = new unordered_set<int>[num_of_ver + 1];
    
    
    for(int i = 0; i < num_of_edge; i++) {
        cin >> in >> out;
        parent[out].insert(in);
        child[in].insert(out);
    }
    
    for(int i = 1; i <= num_of_ver; i++) { if(parent[i].empty()) { check_list.insert(i); } }
}

void Alg::print_in_ord() {
    while(!check_list.empty()) {
        int check = *(check_list.begin());
        
        cout << check << " ";
        for(auto c : child[check]) {
            parent[c].erase(check);
            if(parent[c].empty()) { check_list.insert(c); }
        }
        
        check_list.erase(check);
    }
}
