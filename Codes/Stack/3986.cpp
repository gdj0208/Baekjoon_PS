#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <math.h>

using namespace std;

class Calculater{
public:
    void run();
private:
    stack<char> stk;
    string str;
    int rpt;
    int cnt;
    char tmp;
    
    void getNum(int *num);
    bool check();
    bool isSameSim(char c1, char c2);
};

int main() {
    //srand(time(NULL));
    
    Calculater * calculater = new Calculater;
    if(calculater == NULL) {printf("allocation failed!\n"); return -1;}
    
    calculater->run();
    
    free(calculater);
}
void Calculater::run(){
    getNum(&rpt);
    cnt = 0;
    
    while(rpt--){
        getline(cin, str);
        
        if(check() == true) { cnt++; }
        
        while(!stk.empty()) {stk.pop();}
    }
    cout << cnt;
}
void Calculater::getNum(int *num) { cin >> *num; getchar(); }
bool Calculater::check() {
    for(auto c : str) {
        if(!stk.empty() && c == stk.top()) { stk.pop(); }
        else { stk.push(c); }
    }
    if(stk.empty()) { return true; }
    else { return false; }
}
bool Calculater::isSameSim(char c1, char c2){
    if (c1 == '(' && c2 == ')') { return true; }
    else if(c1 =='[' && c2 ==']') {return true; }
    else { return false; }
}