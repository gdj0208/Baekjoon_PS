#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;


class Alg {
private:
    int num;
    int cnt[10] = {0};
    void get_cnt();
    void print_cnt();
    
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
    cin >> num;
    get_cnt();
    print_cnt();
}

void Alg::get_cnt() {
    int add = 0;
    
    for(int i = 1; num > 0; i *= 10) {
        int last_num = num % 10;
        num /= 10;
        
        cnt[0] -= i;
        for(int n = 0; n < last_num; n++) { cnt[n] += (num + 1)*i; }
        cnt[last_num] += num * i + 1 + add;
        for(int n = last_num + 1; n < 10; n++) { cnt[n] += num*i; }
        
        add += last_num * i;
    }
}

void Alg::print_cnt() {
    for(int i = 0; i < 10; i++) { cout << cnt[i] << "\n"; }
}

