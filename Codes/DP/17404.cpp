//
//  main.cpp
//  Learning
//
//  Created by 구동준 on 2022/10/02.
//

//#include "classtest.hpp"
//#include "DataStructure.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INF 1e9

using namespace std;

class Alg {
private:
    int input[1001][3];
    int dp[1001][3] = {0};
    int rpt;
    int ans = INF;
   
public:
    void run();
    
private:
    void init();
    void solve();
    void print_ans();
};

int main(void){
    Alg* alg = new Alg;
    alg->run();
}


void Alg::run() {
    init();
    solve();
    print_ans();
}

void Alg::init() {
    cin >> rpt;
    for(int i = 1; i <= rpt; i++) {
        for(int j = 0; j < 3; j++) { cin >> input[i][j]; }
    }
}

void Alg::print_ans() {
}

void Alg::solve() {
    for(int color = 0; color < 3; color++) {
        dp[1][0] = input[1][0];
        dp[1][1] = input[1][1];
        dp[1][2] = input[1][2];
        
        if(color == 0) { dp[1][1] = dp[1][2] = INF; }
        else if(color == 1) { dp[1][0] = dp[1][2] = INF; }
        else { dp[1][0] = dp[1][1] = INF; }
        
        for(int y = 2; y <= rpt; y++) {
            dp[y][0] = MIN(dp[y-1][1], dp[y-1][2]) + input[y][0];
            dp[y][1] = MIN(dp[y-1][0], dp[y-1][2]) + input[y][1];
            dp[y][2] = MIN(dp[y-1][0], dp[y-1][1]) + input[y][2];
        }
        
        if(color == 0) { ans = MIN(ans, MIN(dp[rpt][1], dp[rpt][2])); }
        else if(color == 1) { ans = MIN(ans, MIN(dp[rpt][0], dp[rpt][2])); }
        else { ans = MIN(ans, MIN(dp[rpt][0], dp[rpt][1])); }
    }
    
    cout << ans;
}
