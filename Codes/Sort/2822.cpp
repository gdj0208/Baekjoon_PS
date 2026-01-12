#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

class Calculater{
public:
    //Calculater();
    void calculate();
private:
    int tmp;
    struct bestScore{
        int score;
        int pos;
    };
    bestScore scores[8];
    
    void input();
    void sortScore();
    void sortPos();
    void printTotal();
    void printBestScoreLoc();
    void swapScore(bestScore * s1, bestScore * s2);
};
    
int main(void){
    
    Calculater * calculater = new(Calculater);
    calculater->calculate();
    
}

void Calculater::calculate(){
    input();
    sortScore();
    printTotal();
    printBestScoreLoc();
}
void Calculater::input(){
    bestScore tmpScore;
    for(int i = 0; i < 8; i++){
        scanf("%d", &tmp);
        
        scores[i].score = tmp;
        scores[i].pos = i;
    }
}
void Calculater::sortScore(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 7; j++){
            if(scores[j].score < scores[j+1].score) {swapScore(&scores[j], &scores[j+1]);}
        }
    }
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            if(scores[j].pos < scores[j+1].pos) {swapScore(&scores[j], &scores[j+1]);}
        }
    }
}
void Calculater::sortPos(){}
void Calculater::printTotal(){
    int total = 0;
    for(int i = 4; i >= 0; i--){ total += scores[i].score; }
    printf("%d\n", total);
}
void Calculater::printBestScoreLoc(){
    for(int i = 4; i >= 0; i--) {printf("%d ", scores[i].pos + 1);}
}
void Calculater::swapScore(bestScore * s1, bestScore * s2){
    bestScore tmp;
    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}
