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
    queue <int> q;
    int data;
    int num;
    int cnt;
    
    void getNum(int *num);
    void makeQueue(int num);
    void func(queue<int> q);
};

int main() {
    //srand(time(NULL));
    
    Calculater * calculater = new Calculater;
    if(calculater == NULL) {printf("allocation failed!\n"); return -1;}
    
    calculater->run();
    
    free(calculater);
}
void Calculater::run(){
    cnt = 0;
    data = 0;
    
    getNum(&num);
    makeQueue(num);
    func(q);
    cout << data << endl;
}
void Calculater::getNum(int *num) { cin >> *num; }
void Calculater::makeQueue(int num) { for(int i = 1; i <= num; i++) { q.push(i); } }
void Calculater::func(queue<int> q) {
    while ( !q.empty() ){
        data = q.front();
        q.pop();
        
        if(cnt % 2) { q.push(data); }
        
        cnt++;
    }
}
