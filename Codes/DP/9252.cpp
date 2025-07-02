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
    string str_a, str_b;
    int size_of_str_a, size_of_str_b, size_of_lcs;
    int dp[1001][1001] = {0};
    int lcs[1001] = {0};
    
public:
    void run();
    
private:
    void get_string();
    void get_lcs();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}


void Alg::run() {
    get_string();
    get_lcs();
}

void Alg::get_string() {
    cin >> str_a >> str_b;
    
    size_of_str_a = str_a.length();
    size_of_str_b = str_b.length();
}

void Alg::get_lcs() {
    size_of_lcs = 0;
    
    for(int y = 1; y <= size_of_str_b; y++) {
        for(int x = 1; x <= size_of_str_a; x++) {
            
            if(str_a[x-1] == str_b[y-1]) {  dp[y][x] = dp[y-1][x-1] + 1; }
            else { dp[y][x] = max(dp[y][x-1], dp[y-1][x]); }
            
        }
    }
    
    size_of_lcs = dp[size_of_str_b][size_of_str_a];
    
    cout << size_of_lcs << "\n";
    
    int x = size_of_str_a;
    int y = size_of_str_b;
    int max = dp[y][x];
    
    while(x > 0 and y > 0) {
        if(max == dp[y][x-1]) { x--; }
        else { lcs[dp[y][x]] = x; y--; max = dp[y][x]; }
    }
    
    for(int i = 1; i <= size_of_lcs; i++) { cout << str_a[lcs[i] - 1]; }
}


/*
 VREGDFELK
 VLSKD
 */
