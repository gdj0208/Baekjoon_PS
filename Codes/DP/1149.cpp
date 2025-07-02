//
//  main.cpp
//  Learning
//
//  Created by 구동준 on 2022/10/02.
//

//#include "classtest.hpp"
//#include "DataStructure.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

class Alg {
private:
    int sum_arr[3] = {0};
    int tmp_arr[3];
    int rpt;
    int mini = sum_arr[0];
   
public:
    void run();
    
private:
    void get_tmp_arr();
};

int main(void){
    
    Alg* alg = new Alg;
    alg->run();
   
}


void Alg::run() {
    
    cin >> rpt;
    
    cin >> sum_arr[0] >> sum_arr[1] >> sum_arr[2];
    while(--rpt) {
        get_tmp_arr();
    }
    
    if(sum_arr[0] < sum_arr[1]) {
        if(sum_arr[0] < sum_arr[2]) { cout << sum_arr[0]; }
        else {
            if(sum_arr[1] < sum_arr[2]) { cout << sum_arr[1]; }
            else { cout << sum_arr[2]; }
        }
    }
    else {
        if(sum_arr[1] < sum_arr[2]) { cout << sum_arr[1]; }
        else {
            if(sum_arr[0] < sum_arr[2]) { cout << sum_arr[0]; }
            else { cout << sum_arr[2]; }
        }
    }
}

void Alg::get_tmp_arr() {
    cin >> tmp_arr[0] >> tmp_arr[1] >> tmp_arr[2];
    
    tmp_arr[0] = (sum_arr[1] < sum_arr[2] ? tmp_arr[0] + sum_arr[1] : tmp_arr[0] + sum_arr[2]);
    tmp_arr[1] = (sum_arr[0] < sum_arr[2] ? tmp_arr[1] + sum_arr[0] : tmp_arr[1] + sum_arr[2]);
    tmp_arr[2] = (sum_arr[0] < sum_arr[1] ? tmp_arr[2] + sum_arr[0] : tmp_arr[2] + sum_arr[1]);
    
    sum_arr[0] = tmp_arr[0];
    sum_arr[1] = tmp_arr[1];
    sum_arr[2] = tmp_arr[2];
    
    //cout << sum_arr[0] << " " << sum_arr[1] << " " << sum_arr[2] << "\n";
}
