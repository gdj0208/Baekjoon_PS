#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>
#include <unordered_set>

#define INF 1e9

using namespace std;


class Alg {
private:
    int size_of_arr;
    int limit;
    int *arr;
    
public:
    void run();
    
private:
    void solve();
    void init_arr();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}


void Alg::run() {
    cin >> size_of_arr >> limit;
    
    init_arr();
    solve();
}

void Alg::init_arr() {
    arr = new int[size_of_arr];
    for(int i = 0; i < size_of_arr; i++) { cin >> arr[i]; }
}

void Alg::solve() {
    int s = 0;
    int e = 0;
    int min_len = INF;
    int len = 1;
    int sum = 0;
    
    while(s < size_of_arr) {
        if(sum < limit and e < size_of_arr) { 
            sum += arr[e++];
            len++;
        }
        
        //limit <= sum or size_of_arr <= e
        else {
            len--;
            if(limit <= sum) { min_len = min(min_len, len); }
            sum -= arr[s++];
        }
    }
    
    min_len = (min_len == INF) ? 0 : min_len;
    cout << min_len;
}
