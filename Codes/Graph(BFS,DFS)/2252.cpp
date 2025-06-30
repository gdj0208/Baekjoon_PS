//
//  main.cpp
//  Learning
//
//  Created by 구동준 on 2022/10/02.
//

//#include "classtest.hpp"
//#include "DataStructure.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Vertic {
public:
    Vertic(int num) { this->num = num; }
    int num;
    bool visited = false;
    unordered_set<int> in, out;
};

class Alg {
private:
    int num_of_vertics;
    int num_of_visit = 0;
    vector<Vertic*> vertics;
    
public:
    void run();
    
private:
    void init();
    void solve();
    void erase_ver_and_edge(int ver_num);
    void print_people();
};

int main(void){
    Alg* alg = new Alg;
    alg->run();
}


void Alg::run() {
    init();
    solve();
}

void Alg::init() {
    int rpt, s, e;
    
    cin >> num_of_vertics >> rpt;
    
    for(int i = 1; i <= num_of_vertics; i++) { vertics.push_back(new Vertic(i)); }
    
    
    while(rpt--) {
        cin >> s >> e;
        
        s--;
        e--;
        
        vertics[s]->out.insert(e);
        vertics[e]->in.insert(s);
    }
}

void Alg::solve() {
    queue<int> q;

    for (int i = 0; i < num_of_vertics; ++i) {
        if (vertics[i]->in.empty()) { q.push(i); }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current + 1 << " ";

        for (auto e : vertics[current]->out) {
            vertics[e]->in.erase(current);

            if (vertics[e]->in.empty()) {  q.push(e); }
        }
    }
}

void Alg::erase_ver_and_edge(int ver_num) {
    cout << ver_num << " ";
    
    for(auto e : vertics[ver_num-1]->out) {
        if(vertics[e]->visited) { continue; }
        
        vertics[e]->in.erase(ver_num-1);
    }
}
