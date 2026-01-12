#include <iostream>
#include <list>
#include <tuple>

using namespace std;

class MainClass {
public:
    void run();
private:
    int size;
    int *arr;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    cin >> size;
    
    arr = (int*)calloc(size + 1, sizeof(int));
    arr[0] = 1;
    arr[1] = 1;
    
    for(int i = 2; i <= size; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }
    
    cout << arr[size] % 10007;
}
