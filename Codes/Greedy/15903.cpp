#include <iostream>
#include <algorithm>
#include <math.h>
#include <list>

using namespace std;

class MainClass {
public:
    void run();
private:
    long long arr[1000001];
    int size_of_arr;
    int add_count;
    long long ans;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    cin >> size_of_arr >> add_count;
    for(int i = 0; i < size_of_arr; i++) { cin >> arr[i]; }
    
    for(int i = 0; i < add_count; i++) {
        sort(arr, arr+size_of_arr);
        arr[0] = arr[1] = arr[0] + arr[1];
    }
    
    ans = 0;
    for(int i = 0; i < size_of_arr; i++) { ans += arr[i]; }
    
    cout << ans;
}
