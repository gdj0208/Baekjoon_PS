#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class MainClass {
public:
    void run();
private:
    int arr[100001];
    int sum[100001] = {0};
    int size_of_arr;
    int rpt;
    int n, m;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> size_of_arr >> rpt;
    for(int i = 1; i <= size_of_arr; i++) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }
    
    while(rpt--) {
        cin >> n >> m;
        cout << sum[m] - sum[n-1] << "\n";
    }
}
