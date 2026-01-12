#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

#define ll long long

using namespace std;

class MainClass {
public:
    void run();
private:
    int num;
    int data[1000000];
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> num;
    data[1] = 0;
    for(int i = 2; i <= num; i++) {
        data[i] = data[i-1] + 1;
        if(i % 2 == 0) { data[i] = min(data[i], data[i/2] + 1); }
        if(i % 3 == 0) { data[i] = min(data[i], data[i/3] + 1); }
    }
    cout << data[num];
}
