#include <iostream>
#include <algorithm>
#include <list>


using namespace std;

class Alg {
public:
    void run();
    
private:
    vector<int> arr;
    int size, req;
    int start, end, sum;
    int cnt;
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
    
    arr.resize(size);
    for(int i = 0; i < size; i++) { cin >> arr[i]; }
    
    cnt = sum = start = end = 0;
    
    while(start < size) {
        if(sum == req) {
            cnt++;
            if(end < size) { sum += arr[end++]; }
            else { sum -= arr[start++]; }
        }
        else if(sum < req) {
            if(end < size) { sum += arr[end++]; }
            else { break; }
        }
        else if(sum > req){
            sum -= arr[start];
            start++;
        }
    }
    
    cout << cnt;
}
