#include <iostream>
#include <algorithm>
#include <cstring>
#include <list>

#define ll long long
#define INF 1e8

using namespace std;

class MainClass {
public:
    void run();
    
private:
    vector<ll> arr, dp;
    int size;
    
    void get_arr();
    void get_dp();
    int get_loc(ll n);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    get_arr();          // 수열을 입력 받습니다.
    get_dp();           // dp값들을 넣습니다. ( dp에는 최장 증가 수열이 저장됩니다. )
    cout << dp.size();  // 최장 증가 수열의 길이를 반환합니다.
}

void MainClass::get_arr() {
    cin >> size;
    
    arr.resize(size);
    for(int i = 0; i < size; i++) { cin >> arr[i]; }
}

void MainClass::get_dp() {
    int loc = 0;
    
    for(int i = 0; i < size; i++) {
        /*
         1. arr[i]가 최장증가수열 dp에서 들어갈 위치를 탐색합니다.
             예를들어 arr[i]가 7이고, dp = {1,2,5,8,9}일 경우
             -> arr[i]는 dp[2]와 dp[3] 사이에 위치해야 합니다.
                (dp[2] = 5, dp[3] = 8임으로)
             -> 따라서 arr[i]가 들어가야 하는 위치 인덱스 값은 3입니다.
         
         2. 만약 (dp에서 들어갈 위치가 없는 경우 = dp의 가장 큰 값보다 큰 경우) dp 맨 뒤에 추가합니다.
             예를들어 arr[i]가 10이고, dp = {1,2,5,8,9}일 경우
             -> arr[i]는 dp[dp.size() - 1]보가 크기에, arr을 dp 맨 뒤에 추가합니다.
                (dp[dp.size()-1] = 9이고 arr[i] = 10)
         */
        
        // arr[i]가 들어갈 위치 탐색
        loc = get_loc(arr[i]);
        
        // arr[i]가 들어갈 위치에 맞게 dp에 삽입
        if(dp.size() <= loc) { dp.push_back(arr[i]); }
        else { dp[loc] = arr[i]; }
    }
}

int MainClass::get_loc(ll n) {
    // 이분 탐색 알고리즘입니다.
    
    int start(0), end(dp.size());
    int mid((start + dp.size()) / 2);
    
    while(start < end) {
        if(n <= dp[mid]) { end = mid; }
        else { start = mid + 1; }
        mid = (start + end) / 2;
    }
    
    return end;
}
