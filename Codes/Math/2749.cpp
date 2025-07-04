#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>

#define ll long long

const int MOD = 1000000;
const int PISANO_PERIOD = 1500000;
using namespace std;

class Alg {
private:
    ll n;
    int *fibo;
    
public:
    void run();
    
private:
    void get_ans(ll num);

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
    n %= PISANO_PERIOD;
    get_ans(n);
}



void Alg::get_ans(ll num) {
    fibo = new int[num + 1];
    fibo[0] = 0;
    fibo[1] = 1;
    
    for(int i = 2; i <= num; i++) { fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD; }
    
    cout << fibo[num];
}
