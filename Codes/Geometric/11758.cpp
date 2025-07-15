#include <iostream>
#include <algorithm>
#include <limits>
#include <list>

#define ll long long

using namespace std;

class MainClass {
public:
    void run();
private:
    int x[3], y[3];
    int vx[2], vy[2];
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 3; i++) { cin >> x[i] >> y[i]; }
    for(int i = 0; i < 2; i++) {
        vx[i] = x[i+1] - x[i];
        vy[i] = y[i+1] - y[i];
    }
    
    if(vx[0]*vy[1] - vx[1]*vy[0] > 0) { cout << 1; }
    else if(vx[0]*vy[1] - vx[1]*vy[0] < 0) { cout << -1; }
    else { cout << 0; }
}

