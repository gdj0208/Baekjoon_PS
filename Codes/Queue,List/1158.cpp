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

int main()
{
    int n, k;                   // 원형으로 앉은 인원들의 인원수와 k
    list<int> arr, res;              // 리스트
    list<int>::iterator iter;   // 리스트를 가르키는 이터레이터

    
    // 리스트의 길이랑 k 입력
    cin >> n >> k;

    
    // 리스트 숫자 초기화
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }
    
    // 이터레이터 초기화
    iter = arr.begin();
    
    
    // 원에 있는 모든 사람들을 제거
    for (int i = 0; i < n; i++) {

        // k번째 뒤의 인원 지정
        for(int j = 1; j < k; j++){
            // 일단 이터레이터를 다음 리스트를 가르키게 한다.
            // 다음 리스트가 list.end()인 경우 이터레이터가 list.begin()을 가르키게 한다. (선형 리스트)
            if(++iter == arr.end()) {iter = arr.begin();}
        }
        
        // k번째 뒤 인원 제거
        res.push_back(*iter);
        arr.erase(iter++);
        
        // 지우고 나서 이터레이터가 가장 list.end()를 가르키면 list.begin()을 가르키도록 수정 (선형 리스트)
        if(iter == arr.end()) {iter = arr.begin();}
    }

    // 제거된 순서대로 인원 출력
    cout << "<";
    for(auto c : res){
        cout << c;
        if(c != res.back()) {cout << ", ";}
    }
    cout << ">";

}