#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;

class Calculater{
public:
    //Calculater();
    //~Calculater();
    
    void run();
private:
    string str;
    list <char> password;
    list <char>::iterator iter;
    int rpt;
    
    void getRpt();
    void getCode();
    void printCode();
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
    getRpt();
    for(int i = 0; i < rpt; i++){
        getCode();
        printCode();
        password.clear();
    }
}
void Calculater::getRpt(){ cin >> rpt; }
void Calculater::getCode(){
    cin >> str;
    
    iter = password.begin();
    
    for(char p : str){
        switch (p) {
            case '<':
                if(iter != password.begin()){iter--;}
                break;
            case '>':
                if(iter != password.end()){iter++;}
                break;
            case '-':
                if(iter != password.begin()) {iter = password.erase(--iter);}
                break;
            default:
                password.insert(iter, p);
                break;
        }
    }
}
void Calculater::printCode(){
    for(auto c : password){cout << c;}
    cout << '\n';
}


