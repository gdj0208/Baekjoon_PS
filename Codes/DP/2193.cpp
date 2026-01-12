#include <iostream>
#include <algorithm>
#include <list>
#define ll long long
#define x first
#define y second

using namespace std;

class Alg {
public:
    void run();
    
private:
    vector<ll> dp;
    int n;
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    cin >> n;
    
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(1);
    
    for(int i = 3; i <= n; i++) { dp.push_back(dp[i-1] + dp[i-2]); }
    
    cout << dp[n];
}


