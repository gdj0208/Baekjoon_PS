#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>

#define null NULL
using namespace std;


class MainClass {
public:
    void run();
private:
    priority_queue<int> smaller, bigger;
    int rpt, data;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> rpt >> data;
    
    smaller.push(data);
    rpt--;
    cout << smaller.top() << "\n";
    
    while(rpt--) {
        cin >> data;
        
        if(smaller.top() < data) { bigger.push(-data); }
        else { smaller.push(data); }
        
        if(smaller.size() < bigger.size()) {
            smaller.push(-bigger.top());
            bigger.pop();
        }
        else if(smaller.size() > bigger.size() + 1) {
            bigger.push(-smaller.top());
            smaller.pop();
        }
        
        cout << smaller.top() << "\n";
    }
    
}
