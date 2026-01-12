#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <algorithm>

#define ll long long

using namespace std;

class Alg {
private:
    vector<int> pri;
    int N;
    int cnt = 0;
    
    void init_infos();
    void make_prime_list();
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
    init_infos();
    print_ans();
}

void Alg::init_infos() {
    cin >> N;
    make_prime_list();
}

void Alg::print_ans() {
    int s = 0;
    int e = 0;
    int sum = 0;
    
    if(N == 0) { cout << 0; return; }
    
    while(e < pri.size()) {
        if(sum >= N) { sum -= pri[s++]; }
        else if(sum < N) { sum += pri[e++]; }
        if(sum == N) {
            cnt++;
        }
    }
    
    cout << cnt;
}

void Alg::make_prime_list() {
    vector<bool> is_prime;
    
    is_prime.resize(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    
    for(int i = 2; i*i <= N; i++) {
        if(is_prime[i]) {
            for(ll j = i*i; j <= N; j += i) { is_prime[j] = false; }
        }
    }
    
    for(int i = 2; i <= N; i++) { if(is_prime[i]) { pri.push_back(i); } }
    pri.push_back(0);
}

