#include <iostream>
#include <algorithm>

using namespace std;

class Alg {
private:
    int total_cost, unit_num;
    vector<vector<int>> dp;
    vector<pair<int, int>> cost_val;        // 비용, 고객수
    
public:
    void run();
    
private:
    void get_info();
    void knacksack();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    
    get_info();
    knacksack();
    cout << dp[unit_num][total_cost];
    
}

void Alg::get_info() {
    cin >> unit_num >> total_cost;
    
    dp.resize(unit_num + 1, vector<int>());
    for(int i = 0; i <= unit_num; i++) { dp[i].resize(total_cost + 1, 0); }
    
    for(int i = 0; i < unit_num; i++) {
        int n1, n2;
        
        cin >> n1 >> n2;
        cost_val.push_back({n1, n2});
    }
}

void Alg::knacksack() {
    for(int i = 1; i <= unit_num; i++) {
        int cos = cost_val[i-1].first;
        int val = cost_val[i-1].second;
        
        for(int c = 0; c <= total_cost; c++) {
            if(cos <= c){ dp[i][c] = max(dp[i-1][c], dp[i-1][c-cos] + val); }
            else { dp[i][c] = dp[i-1][c]; }
        }
    }
}
