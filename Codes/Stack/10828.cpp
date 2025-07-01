#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <list>
//#include <math.h>
//#include <time.h>
#define dwarf_num 9
#define ori_num 7

using namespace std;
class IntStack{
public:
    IntStack();
    
    void push(int n);
    void pop();
    int size();
    bool empty();
    int top();
private:
    typedef struct Stack{
        int num;
        Stack * behind;
    };
    Stack * stack, * topOfStack;
    int sizeOfStack;
    bool isEmpty;
};

class Calculater{
public:
    IntStack * stack = new(IntStack);
    //Calculater();
    //~Calculater();
    
    void run();
private:
    char str[10];
    int num;
    int rpt;
    
    void getInput();
};

int main() {
    //srand(time(NULL));
    
     Calculater * calculater = new Calculater;
     if(calculater == NULL) {printf("allocation failed!\n"); return -1;}
     
     calculater->run();
     
     free(calculater);
     calculater = NULL;
    
}
IntStack::IntStack(){
    sizeOfStack = 0;
    isEmpty = true;
    
    stack = new Stack;
    stack->num = NULL;
    stack->behind = NULL;
    topOfStack = stack;
}
void IntStack::push(int n){
    stack = new Stack;
    
    stack->num = n;
    stack->behind = topOfStack;
    
    topOfStack = stack;
    
    sizeOfStack++;
}
void IntStack::pop(){
    if(sizeOfStack == 0) {printf("-1\n");return;}
    
    printf("%d\n", top());
    
    topOfStack = stack->behind;
    
    stack->num = NULL;
    stack->behind = NULL;
    
    free(stack);
    
    stack = topOfStack;
    sizeOfStack--;
}
int IntStack::size(){return sizeOfStack;}
bool IntStack::empty(){return sizeOfStack == 0 ? true : false;}
int IntStack::top(){
    if(empty()){return -1;}
    return topOfStack->num;
}

void Calculater::run(){
    scanf("%d", &rpt);
    
    for(int i = 0; i < rpt; i++){
        getInput();
        if(strcmp(str, "push") == 0){stack->push(num);}
        if(strcmp(str, "pop") == 0){stack->pop();}
        if(strcmp(str, "size") == 0){printf("%d\n", stack->size());}
        if(strcmp(str, "empty") == 0){printf("%d\n", stack->empty());}
        if(strcmp(str, "top") == 0){printf("%d\n",stack->top());}
    }
    
}
void Calculater::getInput(){
    scanf("%s", &str);
    if(strcmp(str, "push") == 0) {scanf("%d", &num);}
}