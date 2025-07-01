#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include <stack>
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
    stack <pair<int, int>> tower;
    int num_of_tower;
    
    void input();
    void getNums();
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
    input();
    getNums();
}
void Calculater::input(){
    scanf("%d",&num_of_tower);
}
void Calculater::getNums(){
    int tmp;
    for(int i = 0; i < num_of_tower; i++){
        scanf("%d", &tmp);
        while(!tower.empty() && tower.top().first < tmp) {tower.pop();}
    
        if(tower.empty()) {printf("0 ");}
        else {printf("%d ", tower.top().second + 1);}
        tower.push({tmp, i});
    }
}
