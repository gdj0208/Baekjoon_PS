#include <iostream>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

class MainClass {
public:
    void run();
private:
    bool is_true;
    int rpt;
    string str;
    stack<char> stk;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> rpt;
    while(rpt--) {
        is_true = false;
        
        cin >> str;
        
        for(auto data : str) {
            if(data == '(') { stk.push(data); }
            else if(data == ')') {
                if(stk.empty() or stk.top() != '(') { is_true = true; break; }
                stk.pop();
            }
            
        }
        
        if(!is_true and stk.empty()) { cout << "YES\n"; }
        else { cout << "NO\n"; }
        
        while(!stk.empty()) { stk.pop(); }
    }
}

