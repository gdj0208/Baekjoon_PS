#include <iostream>
#include <algorithm>
#include <set>

#define ll long long
#define div 1000000007

using namespace std;

class Alg {
public:
    void run();
    
private:
    int size, change_cnt, sum_cnt;
    int n1;
    ll n2, n3;
    vector<ll> arr, mul_tree;
    
    void build_mul_tree(int node, int start, int end);
    ll get_mul(int node, int start, int end, ll left, ll right);
    void update_mul(int node, int start, int end, ll loc);
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
    cin >> size >> change_cnt >> sum_cnt;
    
    arr.resize(size);
    for(int i = 0; i < size; i++) { cin >> arr[i]; }
    
    mul_tree.resize(4*size);
    build_mul_tree(1, 0, size-1);
    
    for(int i = 0; i < change_cnt + sum_cnt; i++) {
        cin >> n1 >> n2 >> n3;
        
        if(n1 == 1) { update(n2-1, n3); }
        else { cout << get_mul(1, 0, size-1, n2-1, n3-1) << "\n"; }
    }
}

void Alg::build_mul_tree(int node, int start, int end) {
    if(start == end) { mul_tree[node] = arr[start]; }
    else {
        int mid = (start + end) / 2;
        build_mul_tree(2*node, start, mid);
        build_mul_tree(2*node+1, mid+1, end);
        mul_tree[node] = (mul_tree[2*node] * mul_tree[2*node+1]) % div;
    }
}

ll Alg::get_mul(int node, int start, int end, ll left, ll right) {
    if(right < start or end < left) { return 1; }
    if(left <= start and end <= right) { return mul_tree[node]; }
    
    int mid = (start + end) / 2;
    return (get_mul(2*node, start, mid, left, right) * get_mul(2*node + 1, mid+1, end, left, right)) % div;
}

void Alg::update(ll loc, ll num) {
    arr[loc] = num;
    update_mul(1, 0, size-1, loc);
}

void Alg::update_mul(int node, int start, int end, ll loc) {
    if(loc < start or end < loc) { return; }
    
    if(start == end) { mul_tree[node] = arr[start]; }
    else {
        int mid = (start + end) / 2;
        update_mul(2*node, start, mid, loc);
        update_mul(2*node + 1, mid+1, end, loc);
        mul_tree[node] = (mul_tree[2*node] * mul_tree[2*node+1]) % div;
    }
}
