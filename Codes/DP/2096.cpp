//
//  main.cpp
//  Learning
//
//  Created by 구동준 on 2022/10/02.
//

//#include "classtest.hpp"
//#include "DataStructure.h"

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
#define null NULL
#define Bigger(a,b) a>b ? a:b
#define Smaller(a,b) a<b ? a:b

using namespace std;

class Alg{
private:
    int rpt;
    int max[3];
    int min[3];
    int next[3];
    
public:
    void run();
    void initialize();
    void solve();
    void change_max();
    void change_min();
    int get_biggest_among_three(int a, int b, int c);
    int get_smallest_among_three(int a, int b, int c);
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Alg alg;
    alg.run();
}


void Alg::run() {
    
    initialize();
    solve();
    
}

void Alg::initialize() {
    
    cin >> rpt;
    cin >> max[0] >> max[1] >> max[2];
    
    min[0] = max[0];
    min[1] = max[1];
    min[2] = max[2];
    
}

void Alg::solve() {
    
    while (--rpt) {
        cin >> next[0] >> next[1] >> next[2];
        change_max();
        change_min();
    }
    
    cout << get_biggest_among_three(max[0], max[1], max[2]) << " "
        << get_smallest_among_three(min[0], min[1], min[2]);}

void Alg::change_max() {
    int n[3];
    
    n[0] = Bigger(max[0], max[1]);
    n[0] += next[0];
    
    n[1] = get_biggest_among_three(max[0], max[1], max[2]);
    n[1] += next[1];
    
    n[2] = Bigger(max[1], max[2]);
    n[2] += next[2];
    
    max[0] = n[0];
    max[1] = n[1];
    max[2] = n[2];
}

void Alg::change_min() {
    int n[3];
    
    n[0] = Smaller(min[0], min[1]);
    n[0] += next[0];
    
    n[1] = get_smallest_among_three(min[0], min[1], min[2]);
    n[1] += next[1];
      
    n[2] = Smaller(min[1], min[2]);
    n[2] += next[2];
    
    min[0] = n[0];
    min[1] = n[1];
    min[2] = n[2];
}

int Alg::get_biggest_among_three(int a, int b, int c) {
    int biggest = Bigger(a, b);
    biggest = Bigger(biggest, c);
    
    return biggest;
}

int Alg::get_smallest_among_three(int a, int b, int c) {
    int smallest = Smaller(a, b);
    smallest = Smaller(smallest, c);
    
    return smallest;
}
