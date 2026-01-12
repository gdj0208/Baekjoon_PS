#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>

using namespace std;

class MainClass {
public:
    void run();
private:
    list<int> minus, plus;
    int size_of_arr;
    int max = 0;
    
    void init();
    void get_biggest();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init();
    get_biggest();
}

void MainClass::init() {
    int tmp;
    
    cin >> size_of_arr;
    for(int i = 0 ; i < size_of_arr; i++) {
        cin >> tmp;
        if(tmp == 1) { max++; }
        else if(tmp > 1) { plus.push_back(tmp); }
        else { minus.push_back(tmp); }
    }
    
    minus.sort();
    plus.sort();
}

void MainClass::get_biggest() {
    int n1, n2;
    
    n1 = 0;

    while (1 < minus.size()) {
        n1 = minus.front();
        minus.pop_front();
        
        n2 = minus.front();
        minus.pop_front();
        
        max += n1 * n2;
    }
    if(minus.size() == 1) { max += minus.front(); }
    
    while(1 < plus.size()) {
        n1 = plus.back();
        plus.pop_back();
        
        n2 = plus.back();
        plus.pop_back();
        
        max += n1 * n2;
    }
    if(plus.size() == 1) { max += plus.back(); }
    
    cout << max;
}

