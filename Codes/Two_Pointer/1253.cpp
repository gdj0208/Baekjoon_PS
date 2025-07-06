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
    vector<ll>arr;
    int size = 0;
    
    void init_arr();
    ll get_good();
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init_arr();
    sort(arr.begin(), arr.end());
    cout << get_good();
}

void MainClass::init_arr() {
    int newNum;
    
    cin >> size;
    while(size--) { cin >> newNum; arr.push_back(newNum); }
}

ll MainClass::get_good() {
    ll cnt = 0;
    int start, end, comp;
    int sum = 0;
    
    for(comp = 0; comp < arr.size(); comp++) {
        start = 0;
        end = arr.size() - 1;
        
        while(start < end) {
            sum = arr[start] + arr[end];
            
            if(sum > arr[comp]) { end--; }
            else if(sum < arr[comp]) { start++; }
            else {
                if(comp != start and end != comp) { cnt++; break; }
                else if(start == comp) { start++; }
                else if(end == comp) { end--; }
            }
        }
    }
    
    return cnt;
}