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
#include <stack>
#include <queue>
#include <unordered_set>

#define INF 1e9

using namespace std;


class Alg {
private:
    int *num;
    int size_of_num, rpt;
    int dp[2001][2001] = {0};
    
public:
    void run();
    
private:
    void init();
    void check_dp();
    void solve();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}


void Alg::run() {
    init();
    check_dp();
    solve();
}

void Alg::init() {
    cin >> size_of_num;
    
    num = new int[size_of_num + 1];
    for(int i = 1; i <= size_of_num; i++) { cin >> num[i]; }
}

void Alg::solve() {
    int s, e;
    
    cin >> rpt;
    while(rpt--) {
        cin >> s >> e;
        
        if(dp[s][e]) { cout << "1\n"; }
        else { cout << "0\n"; }
    }
}

void Alg::check_dp() {
    for(int i = 1; i <= size_of_num; i++) { dp[i][i] = true; }
    for(int i = 1; i < size_of_num; i++) if(num[i] == num[i+1]) { dp[i][i+1] = true; }
    for(int len = 3; len <= size_of_num; len++) {
        for(int i = 1; i <= size_of_num - len + 1; i++) {
            int j = i + len - 1;
            if(num[i] == num[j] and dp[i+1][j-1]) { dp[i][j] = true; }
        }
    }
}

