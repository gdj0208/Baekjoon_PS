#include <iostream>
#include <algorithm>

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
    cout << dp[req];
}

void Alg::init_info() {
    cin >> coin_num >> req;
    
    coins.resize(coin_num);
    for(int i = 0; i < coin_num; i++) { cin >> coins[i]; }
    
    dp.resize(req + 1);
    //for(int i = 0; i <= coin_num; i++) { dp[i].resize(req + 1, 0); }
}

void Alg::run_dp() {
    dp[0] = 1;
    
    //for(int i = 0; i <= req; i++) { printf("%2d ", i); }
    //cout << "\n";
    
    for(int i = 0; i < coin_num; i++) {
        for(int m = coins[i]; m <= req; m++) {  dp[m] += dp[m - coins[i]]; }
        //print_dp();
    }
}

void Alg::print_dp() {
    for(int m = 0; m <= req; m++) { printf("%2d ", dp[m]); }
    cout << "\n";
}
