//
//  main.cpp
//  Learning
//
//  Created by 구동준 on 2022/10/02.
//

//#include "classtest.hpp"
//#include "DataStructure.h"

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
#define null NULL
#define MAX(a,b) a>b ? a:b

using namespace std;

class Alg{
private:
    int size;
    int list[1001];
    int smaller[1001] = {0};
    int bigger[1001] = {0};
    
public:
    void run();
    void get_data();
    void rate_big();    // 우측에 더 큰 수의 갯수를 구한다
    void rate_small();  // 좌측에 더 작은 수의 갯수를 구한다
    void print_smaller();
    void print_bigger();
    void print_ans();
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(NULL);
    
    Alg alg;
    alg.run();
}


void Alg::run() {
    
    get_data();
    
    rate_small();
    rate_big();
    
    //print_smaller();
    //print_bigger();
    print_ans();
    
}

void Alg::get_data() {
    cin >> size;
    for(int i = 0; i < size; i++) { cin >> list[i]; }
}

void Alg::rate_big() {
    for(int i = size - 1; i >= 0; i--) {
        for(int j = size - 1; j > i; j--) { if(list[i] > list[j]) { bigger[i] = (bigger[i] > bigger[j]) ? bigger[i] : bigger[j] + 1; } }
    }
}

void Alg::rate_small() {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < i; j++) { if(list[j] < list[i]) { smaller[i] = (smaller[i] > smaller[j]) ? smaller[i] : smaller[j]+1; } }
    }
}

void Alg::print_smaller() {
    for(int i = 0; i < size; i++) {
        cout << smaller[i] << " ";
    }
    cout << "\n";
}

void Alg::print_bigger() {
    for(int i = 0; i < size; i++) {
        cout << bigger[i] << " ";
    }
    cout << "\n";
}

void Alg::print_ans() {
    int max = 0;
    int sum;
    
    for(int i = 0; i < size; i++) {
        sum = smaller[i] + bigger[i];
        max = MAX(sum, max);
    }
    cout << max + 1;
}
