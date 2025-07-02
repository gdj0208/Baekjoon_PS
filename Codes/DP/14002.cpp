#include <iostream>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

class MainClass {
public:
    void run();
private:
    list<int> ans;
    int size_of_list;
    int max_index = 0;
    int li[1000];
    int dp[1000] = {0};
    
    void get_list();
    void get_longest();
    void print_longest();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    get_list();
    get_longest();
    print_longest();
}

void MainClass::get_list() {
    cin >> size_of_list;
    for(int i = 0; i < size_of_list; i++) { cin >> li[i]; }
}

void MainClass::get_longest() {
    for(int i = 1; i < size_of_list; i++) {
        for(int j = 0; j < i; j++) {
            if(li[j] < li[i] and dp[i] < dp[j] + 1) { dp[i] = dp[j] + 1; }
        }
        
        if(max_index < dp[i]) { max_index = dp[i]; }
    }
    
    for(int i = size_of_list - 1; max_index >= 0; i--) {
        if(dp[i] == max_index) { ans.push_front(li[i]); max_index--; }
    }
}

void MainClass::print_longest() {
    cout << ans.size() << endl;
    for(auto iter : ans) { cout << iter << " "; }
}


/*
 4
 10 30 20 30
 
 13
 3 4 5 6 2 3 1 7 4 3 5 6 7
 */
