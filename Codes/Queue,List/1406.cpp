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
    string str;
    list <char> L;
    list <char>::iterator iter;
    int rpt;
    
    void getStr();              // 문자열 입력
    void getRpt();              // 반복횟수 입력
    void getOrder();            // 명령어 입력
    void printString();         // 문자열 출력
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
    getStr();
    getRpt();
    for(int i = 0; i < rpt; i++){
        getOrder();
    }
    printString();
}
void Calculater::getStr(){
    cin >> str;
    
    for(auto i : str){
        L.push_back(i);
    }
    
    iter = L.end();
}
void Calculater::getRpt(){
    cin >> rpt;
}
void Calculater::getOrder(){
    char order, word;
    
    cin >> order;
    
    switch (order) {
        case 'L':   // 이터레이터를 왼쪽으로 한 칸 옮김
            if(iter != L.begin()){iter--;}
            break;
        case 'D':   // 이터레이터를 오른쪽으로 한 칸 옮김
            if(iter != L.end()){iter++;}
            break;
        case 'B':   // 이테리어터 왼쪽 문자 삭제
            if(iter != L.begin()){
                iter--;
                iter = L.erase(iter);
            }
            break;
        case 'P':   // 이터레이터 왼쪽에 문자 추가
            cin >> word;
            L.insert(iter, word);
            break;
        default:
            break;
    }
}
void Calculater::printString(){
    for(auto i : L){
        cout << i;
    }
    cout << endl;
}
