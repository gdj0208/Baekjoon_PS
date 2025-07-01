#include <iostream>
#include <algorithm>
#include <limits>
#include <stack>
#include <list>

using namespace std;

class MainClass {
public:
    void run();
private:
    stack<int> stk;
    int arr[1000000] = {0};
    int ans[1000000] = {0};
    int num;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k = 0;
    
    cin >> num;
    for(int i = 0; i < num; i++) { cin >> arr[i]; }
    
    for(int i = num-1; i >= 0; i--) {
        while(!stk.empty() and arr[i] >= stk.top()) { stk.pop(); }
        if(stk.empty()) { ans[i] = -1; }
        else { ans[i] = stk.top(); }
        
        stk.push(arr[i]);
    }
    
    for(int i = 0; i < num; i++) { cout << ans[i] << " "; }
}

