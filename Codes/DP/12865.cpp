#include <iostream>
#include <algorithm>
#include <limits>
#include <list>

using namespace std;

class MainClass {
public:
    void run();
private:
    int **dp;
    int weight[100002] = {0}, value[100002] = {0};
    int size, limit;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> size >> limit;
    for(int i = 1; i <= size; i++) { cin >> weight[i] >> value[i]; }
    
    dp = new int*[limit + 1];
    for(int w = 0; w <= limit; w++) {
        dp[w] = new int[size + 1];
        for(int x = 0; x <= size; x++) { dp[w][x] = 0; }
    }
    
    for(int w = 1; w <= limit; w++) {
        for(int i = 1; i <= size; i++) {
            if(weight[i] <= w) { dp[w][i] = (dp[w][i-1] > dp[w - weight[i]][i-1] + value[i]) ? dp[w][i-1] : dp[w - weight[i]][i-1] + value[i]; }
            else { dp[w][i] = dp[w][i-1]; }
        }
    }
        
    cout << dp[limit][size];
}
