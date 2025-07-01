//
//  main.cpp
//  Learning
//
//  Created by 구동준 on 2022/10/02.
//

//#include "classtest.hpp"
//#include "DataStructure.h"

#include <iostream>
#include <list>
#include <queue>
#define null NULL
#define MAX(a,b) a>b ? a:b

using namespace std;

class Alg{
private:
    int parent[100001] = {0};
    int num_of_ver;
    list<int> *adj;
    
public:
    void run();
    void init_graph();
    void solve();
    void print_ans();
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(NULL);
    
    Alg alg;
    alg.run();
}


void Alg::run() {
    init_graph();
    solve();
    print_ans();
}

void Alg::init_graph() {
    int v1, v2;
    
    cin >> num_of_ver;
    adj = new list<int>[num_of_ver + 1];
    
    for(int i = 1; i < num_of_ver; i++) {
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
}

void Alg::solve() {
    
    int level = 0;
    int check_ver;
    list<int>check_list, tmp_list;
    
    tmp_list.push_back(1);
    parent[1] = 1;
    
    while(!tmp_list.empty()) {
        
        level++;
        check_list = tmp_list;
        tmp_list.clear();
        
        while(!check_list.empty()) {
            check_ver = check_list.front();
            check_list.pop_front();
            
            for(auto ver : adj[check_ver]) {
                if(parent[ver] != 0) { continue; }
                parent[ver] = check_ver;
                tmp_list.push_back(ver);
            }
        }
    }
    
}

void Alg::print_ans() {
    for(int i = 2; i <= num_of_ver; i++) { cout << parent[i] << "\n"; }
}
