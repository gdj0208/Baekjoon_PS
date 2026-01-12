#include <iostream>
#include <algorithm>
#include <cstring>
#include <list>
#include <unordered_set>

#define ll long long

using namespace std;

class MainClass {
public:
    void run();
    
private:
    int size, loc;
    
    void find();
    int get_lower_nums(int i);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    cin >> size >> loc;
    find();
    
}

void MainClass::find() {
    ll start, end, mid, low, ans;
    
    start = 0;
    end = loc;
    
    while(start < end) {
        mid = (start + end) / 2;
        
        low = get_lower_nums(mid);
        
        if(loc <= low) { ans = end = mid; }
        else if(low < loc) { start = mid + 1; }
    }
    
    cout << end;
}

int MainClass::get_lower_nums(int n) {
    int num = 0;
    for(int i = 1; i <= size; i++) {
        num += min(n/i, size);
    }
    return num;
}
