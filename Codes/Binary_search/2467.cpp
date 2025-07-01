#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

class MainClass {
public:
    void run();
private:
    ll arr[100000];
    int size_of_arr;
    int left, right;
    
    void get_arr();
    void get_finest();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    get_arr();
    get_finest();
}

void MainClass::get_arr() {
    cin >> size_of_arr;
    for(int i = 0; i < size_of_arr; i++) { cin >> arr[i]; }
}

void MainClass::get_finest() {
    ll dif, min_dif, min, max;
    
    left = 0;
    right = size_of_arr - 1;
    
    min = arr[left];
    max = arr[right];
    min_dif = dif = abs(arr[left] + arr[right]);
    
    while(left < right) {
        dif = arr[left] + arr[right];
        if(min_dif > abs(dif)) {
            min_dif = abs(dif);
            min = arr[left];
            max = arr[right];
        }
        
        if(dif < 0) { left++; }
        else if(dif > 0) { right--; }
        else { break; }
    }
    
    cout << min << ' ' << max;
}
