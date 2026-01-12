#include <iostream>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

class MainClass {
public:
    void run();
private:
    int dp[1001][1001] = {0};
    int size_of_string_a, size_of_string_b;
    string string_a, string_b;
    
    void get_strings();
    void get_LCS();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    get_strings();
    get_LCS();
}

void MainClass::get_strings() {
    cin >> string_a >> string_b;
    
    size_of_string_a = string_a.length();
    size_of_string_b = string_b.length();
}

void MainClass::get_LCS() {
    for(int i = 1; i <= size_of_string_a; i++) {
        for(int j = 1; j <= size_of_string_b; j++) {
            if(string_a[i-1] == string_b[j-1]) { dp[i][j] = dp[i-1][j-1] + 1; }
            else { dp[i][j] = max(dp[i-1][j], dp[i][j-1]); }
        }
    }
    
    cout << dp[size_of_string_a][size_of_string_b];
}
