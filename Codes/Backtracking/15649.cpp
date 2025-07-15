#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <math.h>
#include <time.h>

using namespace std;

class MainClass {
public:
    void run();
private:
    int range, size;
    int arr[8];
    bool used[8] = {0};
    
    void init_arr();
    void fill_arr(int loc);
    void print_arr();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    cin >> range >> size;
    
    fill_arr(0);
}

void MainClass::init_arr() {
    for(int i = 0; i < size; i++) { arr[i] = 0; }
}

void MainClass::fill_arr(int loc) {
    if(loc >= size) { print_arr(); return; }
    
    for(int i = 1; i <= range; i++) {
        if(used[i-1]) { continue; }
        
        arr[loc] = i;
        used[i-1] = 1;
        fill_arr(loc + 1);
        used[i-1] = 0;
    }
}

void MainClass::print_arr() {
    for(int i = 0; i < size; i++) { cout << arr[i] << " "; }
    cout << "\n";
}

