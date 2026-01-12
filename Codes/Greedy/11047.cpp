#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Calculater{
public:
    void calculate();
private:
    int coinVarient;
    int * coins;
    int money;
    int ans;
    
    void getCoinVar();
    void getMoney();
    void getCoins();
    void sortData();
    void swapData(int *n1, int *n2);
    void getMinCoins();
    void printAns();
};
int main() {
    
    Calculater * calculater = new Calculater;
    if(calculater == NULL) {printf("allocation failed!\n"); return -1;}

    calculater->calculate();
    
    free(calculater);
    calculater = NULL;
    
}

void Calculater::calculate(){
    getCoinVar();
    ans = 0;
    
    coins = (int*)calloc(coinVarient, sizeof(int));
    if(coins == NULL) {printf("allocation failed!\n");}

    getMoney();
    getCoins();
    sortData();
    getMinCoins();
    printAns();
    
    free(coins);
    coins = NULL;
}
void Calculater::getCoinVar(){scanf("%d", &coinVarient);}
void Calculater::getMoney(){scanf("%d", &money);}
void Calculater::getCoins(){
    for(int i = 0; i < coinVarient; i++){scanf("%d", &coins[i]);}
}
void Calculater::sortData(){
    for(int i = 0; i < coinVarient; i++){
        for(int j = 0; j < coinVarient - 1; j++){
            if(coins[j] < coins[j+1]) {swapData(&coins[j], &coins[j+1]);}
        }
    }
}
void Calculater::swapData(int *n1, int *n2){
    int tmp;
    tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}
void Calculater::getMinCoins(){
    int rpt;
    for(int m = money, i = 0; m > 0; m -= coins[i++] * rpt){
        rpt = m / coins[i];
        ans += rpt;
    }
}
void Calculater::printAns(){printf("%d\n", ans);}
