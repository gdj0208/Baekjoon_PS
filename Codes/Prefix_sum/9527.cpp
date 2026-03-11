#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <utility>

#define ll long long

using namespace std;

class Alg {
private:
    ll s, e;
    
public:
    void run();
    
private:
    ll sum_of_1_bit(ll num);
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    cin >> s >> e;
    cout << sum_of_1_bit(e) - sum_of_1_bit(s - 1);
}

ll Alg::sum_of_1_bit(long long num) {
    if(num == 0) { return 0; }
    
    ll msb = 0;
    while(1LL << (msb + 1) <= num) { msb++; }
    ll sum = 0;
    
    sum += msb * (1LL << (msb - 1));
    sum += num - (1LL << msb) + 1;
    sum += sum_of_1_bit(num - (1LL << msb));
    
    return sum;
}

