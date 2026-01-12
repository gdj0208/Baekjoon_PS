#include <iostream>
#include <algorithm>
#include <map>

#define ll long long

using namespace std;

class Alg {
public:
    void run();
    
private:
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    vector<int> arr;
    int start, end;
    int num, cnt, sum;
    
    cnt = start = end = 0;
    sum = 0;
    
    cin >> num;
    while(start <= num) {
        
        if(sum < num) {
            sum += (++end);
        }
        else if(sum > num) {
            sum -= (start++);
        }
        else {
            cnt++;
            sum += (++end);
        }
    }
    
    cout << cnt;
}
