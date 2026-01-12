#include <iostream>
#include <algorithm>
#include <limits>
#include <stack>

#define null NULL

using namespace std;

class MainClass {
public:
    void run();
private:
    int total_pipes;
    char prev;
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
    
    total_pipes = 0;
    prev = null;
    
    cin >> str;
    
    for(auto data : str) {
        if(data == '(') { stk.push(data); }
        else if(data == ')') {
            stk.pop();
            if(prev == '(') { total_pipes += stk.size(); }
            else { total_pipes += 1; }
        }
        
        prev = data;
    }
    
    cout << total_pipes;
}

