#include <iostream>
#include <algorithm>
#include <limits>
#include <list>

using namespace std;

class MainClass {
public:
    void run();
private:
    int arr[1000];
    int size_of_arr;
    int ans, tmp;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    cin >> size_of_arr;
    for(int i = 0; i < size_of_arr; i++) { cin >> arr[i]; }
    
    sort(arr, arr + size_of_arr);
    
    ans = 0;
    for(int i = 0; i < size_of_arr; i++) {
        tmp = 0;
        for(int j = 0; j <= i; j++) { tmp += arr[j]; }
        ans += tmp;;
    }
    
    cout << ans;
}

