#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class MainClass {
public:
    void run();
private:
    stack<char> stk;
    string str;
    int oper_rank;
    
    bool isNotOperator(char c);
    int get_rank(char c);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    
    cin >> str;
    for(char c : str) {
        if(isNotOperator(c)) {
            cout << c;
        }
        else if(c == '(') { stk.push(c); }
        else if(c == ')') {
            while(stk.top() != '(') { cout << stk.top(); stk.pop(); }
            stk.pop();
        }
        else {
            while(!stk.empty() and get_rank(c) <= get_rank(stk.top())) {
                cout << stk.top(); stk.pop();
            }
            stk.push(c);
        }
    }
    while(!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
}

bool MainClass::isNotOperator(char c) { return ('A' <= c and c <= 'Z') or ('a' <= c and c <= 'z'); }

int MainClass::get_rank(char c) {
    switch (c) {
        case '(':
        case ')':
            return 0;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
            break;
    }
    return -1;
}
