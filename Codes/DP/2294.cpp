#include <iostream>
#include <algorithm>

#define INF 1e8
using namespace std;

class Alg {
private:
    int coin_num, req;
    vector<int> coins;
    vector<int> dp;
    
    void init_info();
    void run_dp();
    void print_dp();
    
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
    
    if(dp[req] == INF) { cout << -1; }
    else { cout << dp[req]; }
    
}

void Alg::init_info() {
    cin >> coin_num >> req;
    
    coins.resize(coin_num);
    for(int i = 0; i < coin_num; i++) { cin >> coins[i]; }
    
    dp.resize(req + 1, INF);
    dp[0] = 0;
}

void Alg::run_dp() {
    //for(int m = 1; m <= req; m++) { printf("%3d", m); }
    //cout << "\n";
    
    for(int i = 0; i < coin_num; i++) {
        for(int m = coins[i]; m <= req; m++) {
            dp[m] = min(dp[m], dp[m - coins[i]] + 1);
        }
        //print_dp();
    }
}

void Alg::print_dp() {
    for(int m = 1; m <= req; m++) { printf("%3d", dp[m]); }
    cout << "\n";
}
