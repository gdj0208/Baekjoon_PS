#include <iostream>
#include <algorithm>
#include <limits>
#include <list>


using namespace std;

class MainClass {
public:
    void run();
    
private:
    vector<vector<int>>dp;
    string A, B;
    
    void init_strings_and_dp();
    void get_dp();
    bool is_out(int i, int j);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    init_strings_and_dp();
    get_dp();
}

void MainClass::init_strings_and_dp() {
    cin >> A >> B;
    
    dp.resize(A.size() + 1);
    for(int i = 0; i <= A.size(); i++) { dp[i].resize(B.size() + 1, 0); }
}

void MainClass::get_dp() {
    int max = 0;
    
    for(int i = 1; i <= A.size(); i++) {
        for(int j = 1; j <= B.size(); j++) {
            if(A[i-1] == B[j-1]) { dp[i][j] = dp[i-1][j-1] + 1; }
            max = (dp[i][j] > max) ? dp[i][j] : max;
        }
    }
    
    cout << max;
}

bool MainClass::is_out(int i, int j) { return i < 0 or j < 0 or A.size() < i or B.size() < j; }

