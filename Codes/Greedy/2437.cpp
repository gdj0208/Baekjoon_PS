#include <iostream>
#include <stdlib.h>
#include <set>
#include <list>
#include <algorithm>

#define INF 1e5

using namespace std;

class Alg {
public:
    void run();
    
private:
    int size;
    vector<int> num;
    set<int> list;
    
    void get_nums();
    void print_nums();
    int get_all_possible_nums();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    
    get_nums();                     // 1. 숫자들 입력 받기
    sort(num.begin(), num.end());   // 2. 숫자들 정렬
    //print_nums();
    cout << get_all_possible_nums();
    
}

void Alg::get_nums() {
    int tmp;
    
    cin >> size;
    for(int i = 0; i < size; i++) { cin >> tmp; num.push_back(tmp); }
}

void Alg::print_nums() {
    for(auto i : num) { cout << i << " "; }
    cout << "\n";
}

int Alg::get_all_possible_nums() {
    int sum = 1;
    
    for(int i = 0; i < size; i++) {
        if(sum < num[i]) { break; }
        sum += num[i];
    }
    
    return sum;
}
