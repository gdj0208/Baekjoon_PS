#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

class Node {
public:
    Node* parent;
    map<string, Node*> child;
};

class Alg {
private:
    Node* tree = new Node();
    void init_tree();
    void make_branch();
    void print_tree(int level, Node* node);
    
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
    init_tree();
}

void Alg::init_tree() {
    int rpt;
    
    cin >> rpt;
    while(rpt--) {
        make_branch();
    }
    print_tree(0, tree);
}

void Alg::make_branch() {
    Node *cur_node, *new_node;
    string name;
    int depth;
    
    // 트리의 branch의 깊이를 입력 받음
    cin >> depth;
    cur_node = tree;
    
    // branch의 깊이 많금 입력
    while(depth--) {
        cin >> name;
        
        // 현 노드 자식 노드들 중 없는 노드일 시에만 생성
        if(cur_node->child.find(name) == cur_node->child.end()) { new_node = new Node(); }
        else { new_node = cur_node->child[name]; }
        
        // 작업한 자식노드를 현 노드로 전환
        cur_node->child.insert({name, new_node});
        new_node->parent = cur_node;
        
        cur_node = new_node;
    }
}

void Alg::print_tree(int level, Node* node) {
    for(auto n : node->child) {
        for(int i = 0; i < level; i++) { cout << "--"; }
        cout << n.first  << "\n";
        
        print_tree(level + 1, n.second);
    }
}
