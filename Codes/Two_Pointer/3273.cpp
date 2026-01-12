#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
//#include <math.h>
//#include <time.h>
#define dwarf_num 9
#define ori_num 7

using namespace std;

int main() {
    /* -- 변수 선언 ------------------------------------- */
    int size, count, compare;
    int * arr, *start, *end;
    
    count = 0;
    
    /* -- 변수 선언 ------------------------------------- */
    
    
    /* -- 배열 입력 ------------------------------------- */
    scanf("%d", &size);
    
    arr = (int*)calloc(size, sizeof(int));
    if(arr == NULL) {cout << "allocation failed!\n";}
    
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &compare);
    /* -- 배열 입력 ------------------------------------- */
    
    sort(arr, arr + size);
    start = arr;
    end = arr + size - 1;
    
    while(start < end){
        if(*start + *end < compare) {start++;}
        else if(*start + *end > compare) {end--;}
        else {count++; start++;}
    }
    
    printf("%d", count);
}