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
    int sizeOfStr;
    char tmp;
    
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
    while(true){
        getline(cin, str);
        if(str == ".") {break;}
        
        
        if(check() == true) { printf("yes\n"); }
        else { cout << "no\n"; }
        
        while(!stk.empty()) {stk.pop();}
    }
}
bool Calculater::check() {
    for(auto c : str) {
        if( c == '(' || c == '[' ) { stk.push(c); }
        else if( c == ')' || c == ']' ) {
            if(stk.empty()) { return false; }
            
            tmp = stk.top();
            stk.pop();
            if ( !isSameSim(tmp, c) ) { return false; }
        }
    }
    if(stk.empty()) { return true; }
    else { return false; }
}
bool Calculater::isSameSim(char c1, char c2){
    if (c1 == '(' && c2 == ')') { return true; }
    else if(c1 =='[' && c2 ==']') {return true; }
    else { return false; }
}
