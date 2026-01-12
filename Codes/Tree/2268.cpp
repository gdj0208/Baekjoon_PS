#include <iostream>
#include <algorithm>
#include <set>

#define ll long long

using namespace std;

class Alg {
public:
    void run();
    
private:
    int size, oper_cnt;
    int n1;
    ll n2, n3;
    vector<ll> arr, sum_tree;
    
    void build_sum_tree(int node, int start, int end);
    ll get_sum(int node, int start, int end, ll left, ll right);
    void update_sum(int node, int start, int end, ll loc, ll diff);
    void update(ll loc, ll num);
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    cin >> size >> oper_cnt;
    
    arr.resize(size, 0);
    
    sum_tree.resize(4*size);
    build_sum_tree(1, 0, size-1);
    
    for(int i = 0; i < oper_cnt; i++) {
        cin >> n1 >> n2 >> n3;
        
        if(n1 == 1) { update(n2-1, n3); }
        else {
            if(n2 > n3) {
                ll tmp = n2;
                n2 = n3;
                n3 = tmp;
            }
            cout << get_sum(1, 0, size-1, n2-1, n3-1) << "\n";
        }
    }
}

void Alg::build_sum_tree(int node, int start, int end) {
    if(start == end) { sum_tree[node] = arr[start]; }
    else {
        int mid = (start + end) / 2;
        build_sum_tree(2*node, start, mid);
        build_sum_tree(2*node+1, mid+1, end);
        sum_tree[node] = sum_tree[2*node] + sum_tree[2*node+1];
    }
}

ll Alg::get_sum(int node, int start, int end, ll left, ll right) {
    if(right < start or end < left) { return 0; }
    if(left <= start and end <= right) { return sum_tree[node]; }
    
    int mid = (start + end) / 2;
    return get_sum(2*node, start, mid, left, right) + get_sum(2*node + 1, mid+1, end, left, right);
}

void Alg::update(ll loc, ll num) {
    ll diff = num - arr[loc];
    arr[loc] = num;
    update_sum(1, 0, size-1, loc, diff);
}

void Alg::update_sum(int node, int start, int end, ll loc, ll diff) {
    if(loc < start or end < loc) { return; }
    sum_tree[node] += diff;
    if(start != end) {
        int mid = (start + end) / 2;
        update_sum(2*node, start, mid, loc, diff);
        update_sum(2*node + 1, mid+1, end, loc, diff);
    }
}