#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <math.h>

#define null NULL
#define max 64

using namespace std;

class MainClass {
public:
    void run();
private:
    int size;
    int cnt_0, cnt_min, cnt_plus;
    
    void div_and_count(int *arr[], int x, int y, int div_size);
    bool all_same(int *arr[], int x, int y, int div_size);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    int *arr[max];
    
    cin >> size;
    for(int y = 0; y < size; y++) {
        arr[y] = new int[size];
        for(int x = 0; x < size; x++) { scanf("%1d", &arr[y][x]); }
    }
    
    cnt_0 = cnt_min = cnt_plus = 0;
    div_and_count(arr, 0, 0, size);
}

void MainClass::div_and_count(int *arr[], int x, int y, int div_size) {
    int half = div_size / 2;
    
    if(all_same(arr, x, y, div_size)) { cout << arr[y][x]; return; }
    
    cout << "(";
    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(all_same(arr, x + j*half, y + i*half, half)) { cout << arr[y + i*half][x + j*half]; }
            else { div_and_count(arr, x + j * half, y + i * half, half); }
        }
    }
    
    cout << ")";
}


bool MainClass::all_same(int *arr[], int x, int y, int div_size) {
    int n = arr[y][x];
    for(int y1 = y; y1 < y + div_size; y1++) {
        for(int x1 = x; x1 < x + div_size; x1++) { if(n != arr[y1][x1]) { return false; } }
    }
    return true;
}

