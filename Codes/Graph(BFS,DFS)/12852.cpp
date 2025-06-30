#include <iostream>
#include <algorithm>
#include <limits>
#include <list>

using namespace std;

class MainClass {
public:
    void run();
private:
    int arr[1000001] = {0};
    int prev[1000001] = {0};
    int num;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    arr[1] = 0;
    
    cin >> num;
    
    for(int i = 2; i <= num; i++) {
        arr[i] = arr[i-1] + 1;
        prev[i] = i-1;
        if(i % 2 == 0 and arr[i/2] + 1 < arr[i]) {
            arr[i] = min(arr[i], arr[i/2] + 1);
            prev[i] = i/2;
        }
        if(i % 3 == 0 and arr[i/3] + 1 < arr[i]) {
            arr[i] = arr[i/3] + 1;
            prev[i] = i/3;
        }
    }
    
    cout << arr[num] << "\n";
    while(true) {
        cout << num << " ";
        if(num <= 1) { break; }
        num = prev[num];
    }
}
