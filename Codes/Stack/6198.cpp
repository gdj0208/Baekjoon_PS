#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

class Calculater{
public:
    
    void run();
private:
    stack <int> building;
    
    long long count;
    long long total;
    int rpt;
    int tmp;
    
    void check();
    void getRpt();
    void getInput();
    void printTotal();
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
    check();
    printTotal();
}
void Calculater::getRpt(){ cin >> rpt; }
void Calculater::getInput(){ cin >> tmp; }
void Calculater::check(){
    count = 0;
    total = 0;
    
    getRpt();
    
    for(int i = 0; i < rpt; i++){
        getInput();
        
        if(building.empty()) {building.push(tmp);}
        else {
            while(!building.empty() && building.top() <= tmp){
                //count++;
                building.pop();
            }
            //total += count;
            total += building.size();
            //count = 0;
            
            building.push(tmp);
        }
    }
    
    //tmp = building.top();
    //building.pop();
    //if(building.top() > tmp) {total++;}
}
void Calculater::printTotal() {cout << total << endl;}