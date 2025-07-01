#include <iostream>
#include <algorithm>

#define INF 1000000000
using namespace std;

class Alg {
private:
    vector<long long> list;
    vector<pair<long long,long long>> tree;
    int list_size, rpt;
    
    void init();
    void print_list();
    pair<long long, long long> getMaxMin(int left, int right, int node, int start, int end) ;
    pair<long long, long long> init_tree(int sp, int ep, int node);
    
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
    pair<long long, long long> MaxMin;
    int sp, ep;
    
    init();
    //print_list();
    
    while(rpt--) {
        cin >> sp >> ep;
        MaxMin = getMaxMin(sp, ep, 1, 1, list_size);
        cout << MaxMin.first << " " << MaxMin.second << "\n";
    }
}

void Alg::print_list() {
    for(int i = 0; i < list_size; i++) { cout << list[i] << " "; }
    cout << "\n";
}

void Alg::init() {
    cin >> list_size >> rpt;
    list.resize(list_size + 1);
    
    for(int i = 1; i <= list_size; i++) { cin >> list[i]; }
    
    tree.resize(list_size *4);
    init_tree(1, list_size, 1);
}

pair<long long, long long> Alg::init_tree(int sp, int ep, int node) {
    if(sp == ep) {
        tree[node].first = list[sp];
        tree[node].second = list[sp];
        return tree[node];
    }
    
    int mp = (sp + ep) / 2;
    pair<long long, long long> leftTree = init_tree(sp, mp, node * 2);
    pair<long long, long long> rightTree = init_tree(mp + 1, ep, node * 2 + 1);
    
    tree[node].first = min(leftTree.first, rightTree.first);
    tree[node].second = max(leftTree.second, rightTree.second);
    return tree[node];
}

pair<long long, long long> Alg::getMaxMin(int left, int right, int node, int start, int end) {
    if (start > right || end < left)
        return make_pair(INF, 1);

    if (left <= start && right >= end)
        return tree[node];

    pair<long long, long long> temp_left = getMaxMin(left, right, node*2, start, (start+end)/2);
    pair<long long, long long> temp_right = getMaxMin(left, right, node*2+1, (start+end)/2+1, end);
    pair<long long, long long> result;

    result.first = min(temp_left.first, temp_right.first);
    result.second = max(temp_left.second, temp_right.second);



    return result;
}
