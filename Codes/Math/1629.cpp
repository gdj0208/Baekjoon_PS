#include <iostream>
#include <list>
#include <algorithm>
#include <queue>

#define  ll long long

using namespace std;

class MainClass {
public:
    void run();
private:
    ll num, mul, mod;
    ll div(ll num, ll mul, ll mod);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    cin >> num >> mul >> mod;
    cout << div(num, mul, mod);
}

ll MainClass::div(ll num, ll mul, ll mod) {
    ll val;
    
    if(mul == 1) { return num % mod; }
    
    val = div(num, mul / 2, mod);
    val = val * val % mod;
    
    if(mul % 2 == 0) { return val; }
    return val * num % mod;
}