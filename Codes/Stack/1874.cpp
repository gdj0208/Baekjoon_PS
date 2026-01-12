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
    list<char> li;
    int arr[100000] = {0};
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
    
    for(int i = 1; i <= num; i++) {
        if(arr[k] >= i) {
            stk.push(i);
            li.push_back('+');
        }
        while(!stk.empty() and arr[k] == stk.top() and k < num) {
            stk.pop();
            li.push_back('-');
            k++;
        }
    }
    if(stk.empty()) { for(auto i : li) { cout << i << "\n"; } }
    else { cout << "NO"; }
}

