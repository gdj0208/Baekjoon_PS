#include <iostream>
#include <algorithm>
#include <cstring>
#include <list>
#include <unordered_set>


using namespace std;

class MainClass {
public:
    void run();
    
private:
    string a,b,c;
    int a_size, b_size, c_size;
    vector<vector<vector<int>>> dp;
    
    void init_strings();
    void init_dp();
    int get_lcs();
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init_strings();
    cout << get_lcs();
}

void MainClass::init_strings() {
    cin >> a >> b >> c;
    
    a_size = a.size();
    b_size = b.size();
    c_size = c.size();
}

int MainClass::get_lcs() {
    init_dp();
    
    for(int i = 1; i <= a_size; i++) {
        for(int j = 1; j <= b_size; j++) {
            for(int k = 1; k <= c_size; k++) {
                if(a[i-1] == b[j-1] and b[j-1] == c[k-1]) { dp[i][j][k] = dp[i-1][j-1][k-1] + 1; }
                else { dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]); }
            }
        }
    }
    
    return dp[a_size][b_size][c_size];
}

void MainClass::init_dp() {
    dp.resize(a_size+1);
    for(int i = 0; i <= a_size; i++) {
        dp[i].resize(b_size+1);
        for(int j = 0; j <= b_size; j++) {
            dp[i][j].resize(c_size+1, 0);
        }
    }
}
