#include <iostream>
#include <algorithm>
#include <limits>
#include <list>

using namespace std;

class MainClass {
public:
    void run();
private:
    int size, ans;
    int A[50];
    int A_pri[50] = {0};
    int B[50];
    int B_pri[50] = {0};
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    cin >> size;
    for(int i = 0; i < size; i++) { cin >> A[i]; }
    for(int i = 0; i < size; i++) { cin >> B[i]; }
    
    sort(A, A + size);
    sort(B, B + size, greater<>());
    
    ans = 0;
    for(int i = 0; i < size; i++) { ans += A[i]*B[i]; }
    
    cout << ans;
}

