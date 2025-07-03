#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
#define null NULL
#define INF 1e9

using namespace std;

class Alg{
private:
    vector<int> tree;
    
public:
    void run();
    void init_tree();
    void print_tree(int s, int e);
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(NULL);
    
    Alg alg;
    alg.run();
}


void Alg::run() {
    
    init_tree();
    print_tree(1, tree.size());
}

void Alg::init_tree() {
    int tmp;
    tree.push_back(INF);
    
    while(scanf("%d", &tmp) != EOF) { tree.push_back(tmp); }
}

void Alg::print_tree(int s, int e) {
    if(s >= e) { return; }
    if(s + 1 == e) { cout << tree[s] << "\n"; return; }
    
    int m = s + 1;
    while(m < e and tree[s] >= tree[m]) { m++; }    // 조사중인 노드의 값보다 더 작은 큰 자식노드가 나올 때 까지 탐색
    
    print_tree(s + 1, m);                           // 조사중인 노드보다 작은 값을 지닌 자식 노드들 탐색
    print_tree(m, e);                           // 조사중인 노드보다 큰 값을 지닌 자식 노드들 탐색
    cout << tree[s] << "\n";
}
