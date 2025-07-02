#include <iostream>
#include <list>
#include <tuple>

using namespace std;

class MainClass {
public:
    void run();
private:
    int size;
    int **arr, **sum;
    
    void initArr();
    void getSum();
    void printBiggest();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    initArr();
    getSum();
    printBiggest();
}

void MainClass::initArr() {
    cin >> size;
    
    // 배열 생성
    arr = (int**)calloc(size, sizeof(int*));
    sum = (int**)calloc(size, sizeof(int*));
    
    for(int i = 0; i < size; i++) {
        arr[i] = (int*)calloc(size, sizeof(int));
        sum[i] = (int*)calloc(size, sizeof(int));
    }
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            arr[i][j] = sum[i][j] = 0;
        }
    }
    
    // 배열 입력
    for(int i = 0; i < size; i++) {
        for(int j = 0; j <= i; j++) { cin >> sum[i][j]; }
    }
}

void MainClass::getSum() {
    for(int i = 1; i < size; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) { sum[i][j] = sum[i-1][j] + sum[i][j]; }
            else { sum[i][j] = sum[i-1][j] > sum[i-1][j-1] ? sum[i-1][j] + sum[i][j] : sum[i-1][j-1] + sum[i][j]; }
        }
    }
}

void MainClass::printBiggest() {
    int biggest = sum[size - 1][0];
    
    for(int i = 1; i < size; i++) { biggest = biggest > sum[size - 1][i] ? biggest : sum[size - 1][i]; }
    
    cout << biggest;
}
