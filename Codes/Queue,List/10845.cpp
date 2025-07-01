#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <math.h>

#define push_oper 1
#define pop_oper 2
#define size_oper 3
#define empty_oper 4
#define front_oper 5
#define back_oper 6

using namespace std;

class Calculater{
public:
    
    void run();
private:
    queue<int> q_list;
    string oper;
    int rpt;
    
    int getOper();
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
    int tmp;
    
    // 명령을 반복할 횟수 입력
    cin >> rpt;
    
    // 명령 수행
    for(int i = 0; i < rpt; i++){
        cin >> oper;
        
        switch (getOper()) {
            case push_oper:
                cin >> tmp;
                q_list.push(tmp);
                break;
            case pop_oper:
                if(q_list.empty()) {cout << -1 << endl;}
                else {cout << q_list.front() << endl; q_list.pop();}
                break;
            case size_oper:
                cout << q_list.size() << endl;
                break;
            case empty_oper:
                cout << q_list.empty() << endl;
                break;
            case front_oper:
                if(q_list.empty()) {cout << -1 << endl;}
                else {cout << q_list.front() << endl;}
                break;
            case back_oper:
                if(q_list.empty()) {cout << -1 << endl;}
                else {cout << q_list.back() << endl;}
                break;
            default:
                break;
        }
    }
}
int Calculater::getOper(){
    if(oper == "push") {return push_oper;}
    else if(oper == "pop") {return pop_oper;}
    else if(oper == "size") {return size_oper;}
    else if(oper == "empty") {return empty_oper;}
    else if(oper == "front") {return front_oper;}
    else if(oper =="back" ) {return back_oper;}
    else {return -1;}
}