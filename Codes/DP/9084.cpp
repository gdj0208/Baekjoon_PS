#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

class Alg {
private:
    int rpt;                    // 테스트 케이스 반복 횟수
    int num_of_diff_coins;      // 동전의 종류
    vector<int> coins,cases;    // 동전별 가격, i원을 채우는 경우들
    int money;                  // 목표 금액
    
public:
    void run();
    
private:
    void init_coin_info();              // 동전 정보 초기화
    void print_ways_to_make_money();    // 목표 금액 달성하는 방법의 수 구하기
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    cin >> rpt;
    while(rpt--) {
        init_coin_info();
        cin >> money;
        print_ways_to_make_money();
    }
}

void Alg::init_coin_info() {
    cin >> num_of_diff_coins;
    coins.resize(num_of_diff_coins);
    
    for(int i = 0; i < num_of_diff_coins; i++) { cin >> coins[i]; }
}

void Alg::print_ways_to_make_money() {
    cases.resize(money + 1);
    fill(cases.begin(), cases.end(), 0);
    
    cases[0] = 1;
    for(int i = 0; i < num_of_diff_coins; i++) {
        /*
         i번째 코인에 대해 해당 코인의 값보다 큰 수에 대해 코인의 값보다 작을때 케이스를 더함
         i번째 코인이 5인 경우 5보다 큰 수들에 대해 그 수보다 5 작을 때의 케이스를 더함
         */
        for(int j = coins[i]; j <= money; j++) { cases[j] += cases[j - coins[i]]; }
    }
    
    cout << cases[money] << "\n";
}
