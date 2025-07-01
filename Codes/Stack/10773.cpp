#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

class Calculater{
public:
    void run();
private:
    typedef struct StackData{
        int n;
        struct StackData * next;
    }StackData;
    StackData * list;
    StackData * top;
    
    int rpt, tmp;
    
    void getRpt();
    void getNum();
    void push(int n);
    void pop();
    void printAll();
    void getTotal();
};
    
int main(void){
    
    Calculater * calculater = new Calculater();
    calculater->run();
    free(calculater);
    calculater = NULL;
    
}
void Calculater::run(){
    list = new StackData();
    top = list;
    
    list->n = NULL;
    list->next = NULL;
    
    getRpt();
    getNum();
    getTotal();
    //printAll();
}
void Calculater::getRpt(){scanf("%d", &rpt);}
void Calculater::getNum(){
    for(int i = 0; i<rpt; i++){
        scanf("%d", &tmp);
        
        if(tmp == 0) {pop();}
        else {push(tmp);}
        
        //printAll();
    }
}
void Calculater::push(int n){
    top = new StackData();
    top->n = n;
    top->next = list;
    list = top;
}
void Calculater::pop(){
    if(top->n == NULL){ return; }
    
    top = list->next;
    
    list->n = NULL;
    list->next = NULL;
    free(list);
    list = top;
    
};
void Calculater::printAll(){
    for(StackData * tmp = top; tmp->next != NULL; tmp = tmp->next){
        printf("%d ", tmp->n);
    }
    printf("\n");
}
void Calculater::getTotal(){
    int total = 0;
    
    for(StackData * tmp = top; tmp->next != NULL; tmp = tmp->next){
        total += tmp->n;
    }
    
    printf("%d\n", total);
}
