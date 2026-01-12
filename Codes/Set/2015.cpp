#include <iostream>
#include <algorithm>
#include <map>

#define ll long long

using namespace std;

class Alg {
public:
    void run();
    
private:
    vector<ll> arr, sums;
    map<int, ll> m;
    int size, req;
    int start, end;
    ll cnt;
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    cin >> size >> req;
    
    arr.resize(size+1);
    sums.resize(size+1);
    
    for(int i = 1; i <= size; i++) { cin >> arr[i]; }
    
    ll cnt = 0;
    sums[0] = 0;
    m[0] = 1;
    for(int i = 1; i <= size; i++) {
        sums[i] = sums[i-1] + arr[i];
        cnt += m[sums[i]-req];
        m[sums[i]]++;
    }
    
    cout << cnt;
}
