#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
//#include <math.h>
//#include <time.h>
#define dwarf_num 9
#define ori_num 7

using namespace std;
class Calculater{
public:
    //Calculater();
    //~Calculater();
    
    void run();
private:
    int number[10];
    int num, need;
    
    void input();
    void count();
    void getNeed();
    void output();
};

int main() {
    //srand(time(NULL));
    
     Calculater * calculater = new Calculater;
     if(calculater == NULL) {printf("allocation failed!\n"); return -1;}
     
     calculater->run();
     
     free(calculater);
     calculater = NULL;
    
}

void Calculater::run(){
    need = 0;
    input();
    count();
    getNeed();
    output();
}
void Calculater::input(){cin >> num;}
void Calculater::count(){
    for(int i = num; i > 0; i/= 10){
        number[i%10]++;
    }
}
void Calculater::getNeed(){
    int max = 0;
    bool sixOrNine = false;
    
    for(int i = 0; i < 10; i++){
        if(i == 6 || i == 9) {continue;}
        else{max = max > number[i] ? max : number[i];}
    }
    max = max > (number[6] + number[9] + 1)/2 ? max : (number[6] + number[9] + 1)/2;
    
    need = max;
}
void Calculater::output(){cout << need << endl;}