#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

#define ll long long

using namespace std;

class Alg {
public:
    void run();
    
private:
    vector<bool> arr;
    ll min_num, max_num;
    int cnt = 0;
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    cin >> min_num >> max_num;
    
    ll range = max_num - min_num + 1;
    arr.resize(range, true);

    for (ll i = 2; i * i <= max_num; i++) {
        ll start = max(i * i, (min_num + i * i - 1) / (i * i) * (i * i));
        for (ll j = start; j <= max_num; j += i * i) {
            arr[j - min_num] = false;
        }
    }

    for (ll i = 0; i < range; i++) {
        if (arr[i]) cnt++;
    }
    cout << cnt << endl;
}
