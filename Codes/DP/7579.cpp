#include <iostream>
#include <algorithm>

using namespace std;

class Alg {
private:
    int size, mems_req, max_size;
    vector<vector<int>> dp;
    vector<int> mems, costs;
    
    void init_info();
    void run_dp();
    void print_dp();
    void print_ans();
    
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
    init_info();
    run_dp();
    //print_dp();
    print_ans();
}

void Alg::init_info() {
    int tmp;
    max_size = 0;
    
    cin >> size >> mems_req;
    
    for(int i = 0; i < size; i++) { cin >> tmp; mems.push_back(tmp); }
    for(int i = 0; i < size; i++) { cin >> tmp; costs.push_back(tmp); max_size += tmp; }
    
    dp.resize(size + 1);
    for(int i = 0; i <= size; i++) { dp[i].resize(max_size + 1, 0); }
}

void Alg::run_dp() {
    for(int i = 1; i <= size; i++) {
        for(int c = 0; c <= max_size; c++) {
            if(c - costs[i-1] >= 0) { dp[i][c] = max(dp[i][c], dp[i-1][c-costs[i-1]] + mems[i-1]); }
            dp[i][c] = max(dp[i][c], dp[i-1][c]);
        }
    }
    
    //cout << dp[size][mems_req];
}

void Alg::print_dp() {
    for(int i = 1; i <= size; i++) {
        for(int m = 0; m <= max_size; m++) { printf("%3d ", dp[i][m]); }
        cout << "\n";
    }
}

void Alg::print_ans() {
    for(int i = 0; i <= max_size; i++) { if(dp[size][i] >= mems_req) { cout << i; break; } }
}

/*
 5 6
 3 1 2 3 4
 3 0 3 5 4
 */
