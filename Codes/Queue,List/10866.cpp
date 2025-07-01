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
    list<int> li;
    string oper;
    int rpt, data;
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
        cin >> oper;
        
        if(oper == "push_back") {
            cin >> data;
            li.push_back(data);
        }
        else if(oper == "push_front") {
            cin >> data;
            li.push_front(data);
        }
        else if(oper == "pop_front") {
            if(li.empty()) { cout << -1 << "\n"; }
            else {
                cout << li.front() << "\n";
                li.pop_front();
            }
        }
        else if(oper == "pop_back") {
            if(li.empty()) { cout << -1 << "\n"; }
            else {
                cout << li.back() << "\n";
                li.pop_back();
            }
        }
        else if(oper == "size") { cout << li.size() << "\n"; }
        else if(oper == "empty") {
            if(li.empty()) { cout << 1 << "\n"; }
            else { cout << 0 << "\n"; }
        }
        else if(oper == "front") {
            if(li.empty()) { cout << -1 << "\n"; }
            else { cout << li.front() << "\n"; }
        }
        else if(oper == "back") {
            if(li.empty()) { cout << -1 << "\n"; }
            else { cout << li.back() << "\n"; }
        }
    }
}

