#include <iostream>
#include <algorithm>
#include <time.h>
#include <list>

using namespace std;

class Flower {
public:
    Flower(int m1, int d1, int m2, int d2) {
        start = m1 * 100 + d1;
        end = m2 * 100 + d2;
    }
    int start, end;
};

class MainClass {
public:
    void run();
private:
    vector<Flower*> Flowers;
    int number_of_flower;
    
    int get_longest(int t);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    int m1, m2, d1, d2;
    int t, nxt_t;
    int flowers_needed = 0;
    Flower* tmp;
    
    cin >> number_of_flower;
    for(int i = 0; i < number_of_flower; i++) {
        cin >> m1 >> d1 >> m2 >> d2;
        Flowers.push_back(new Flower(m1, d1, m2, d2));
    }
    
    //for(auto i : Flowers) { cout << (*i).start.first << " " << (*i).start.second << " " << (*i).end.first << " " << (*i).end.second << "\n"; }
    /*
     맨 앞 꽃의 피는 날짜 < 3월 or 맨 뒤 꽃의 지는 날짜 < 12월 -> 0
     1. 현 월과 일 = 맨 앞 꽃의 지는 날짜
     2. 꽃 수 += 1
     3. 피는 날짜가 현 월과 일보다 빠른 꽃 중 피는 기간이 젤 긴 꽃을 선택
     4. 꽃 수 += 1
     5. 현 월과 일 = 해당 꽃의 지는 날짜
     6. 현 월과 일 < 12월 일 경우 반복
     */
    
    t = 301;
    while(t < 1201) {
        nxt_t = get_longest(t);
        
        if(nxt_t == t) { cout << 0; return; }
        
        flowers_needed++;
        t = nxt_t;
    }
    
    cout << flowers_needed;
}

int MainClass::get_longest(int t) {
    int last_day = t;
    
    for(auto flower : Flowers) {
        if(flower->start <= t and t < flower->end) { last_day = max(last_day, flower->end); }
    }
    
    return last_day;
}
