#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <math.h>

#define null NULL
#define ll long long

using namespace std;

class MainClass {
public:
    void run();
private:
    int n, r, c;
    ll max;
    ll findnum(int x, int y, int div_x, int div_y, int size);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> r >> c;
    max = (ll)pow(2, n);
    ll ans = findnum(c, r, max/2, max/2, max);
    cout << ans;
}

ll MainClass::findnum(int x, int y, int div_x, int div_y, int size) {
    int half = size / 2;
    
    if(size == 2) {
        if(x < div_x and y < div_y) { return 0; }
        else if(div_x <= x and y < div_y) { return 1; }
        else if(x < div_x and div_y <= y) { return 2; }
        else { return 3; }
    }
    
    if(x < div_x and y < div_y) { return findnum(x, y, div_x - half/2, div_y - half/2, half); }
    else if(div_x <= x and y < div_y) { return half*half + findnum(x, y, div_x + half/2, div_y - half/2, half); }
    else if(x < div_x and div_y <= y) { return 2*half*half + findnum(x, y, div_x - half/2, div_y + half/2, half); }
    else { return 3*half*half + findnum(x, y, div_x + half/2, div_y + half/2, half); }
}
