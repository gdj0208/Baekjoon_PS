#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
#include <list>
#include <stack>

#define INF 1e11
#define ll long long


using namespace std;

class Alg{
private:
    int size, rpt;
    int left, right;
    vector<ll> list;
    vector<ll> tree;
    
    void init_list_and_tree();
    void build_tree(int node, int start, int end);
    ll get_min(int node, int start, int end);
    
public:
    void run();
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Alg alg;
    alg.run();
}


void Alg::run() {
    init_list_and_tree();
    while(rpt--) {
        cin >> left >> right;
        cout << get_min(1, 1, size) << "\n";
    }
}

void Alg::init_list_and_tree() {
    cin >> size >> rpt;
    
    list.resize(size+1);
    tree.resize(4*size);
    
    for(int i = 1; i <= size; i++) { cin >> list[i]; }
    build_tree(1, 1, size);
}

void Alg::build_tree(int node, int start, int end) {
    if(start == end) { tree[node] = list[start]; }
    else {
        int mid = (start + end) / 2;
        
        build_tree(2*node, start, mid);
        build_tree(2*node+1, mid+1, end);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

ll Alg::get_min(int node, int start, int end) {
    if(right < start or end < left) { return INF; }
    if(left <= start and end <= right) { return tree[node]; }
    
    if(start == end) { return tree[node]; }
    else {
        int mid = (start + end) / 2;
        ll left_side = get_min(2*node, start, mid);
        ll right_side = get_min(2*node+1, mid+1, end);
        return min(left_side, right_side);
    }
}
