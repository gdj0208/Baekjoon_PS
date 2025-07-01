#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <utility>

using namespace std;

class Alg {
private:
    int arr[1000001];
    int size_of_arr;
    vector<int> LIS;
    
public:
    void run();
    
private:
    void init_data();
    void print_max();
    int find_loc(int n);
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    init_data();
    print_max();
}

void Alg::init_data() {
    cin >> size_of_arr;
    for(int i = 1; i <= size_of_arr; i++) { cin >> arr[i]; }
}

void Alg::print_max() {
    //int ret = 0;
    LIS.push_back(arr[1]);
    
    for(int i = 2; i <= size_of_arr; i++) {
        if(LIS.back() < arr[i]) {
            LIS.push_back(arr[i]);
            //ret = LIS.size() - 1;
        }
        else {
            int loc = find_loc(arr[i]);
            LIS[loc] = arr[i];
        }
    }
    
    cout << LIS.size();
}

int Alg::find_loc(int n) {
    int start = 0;
    int end = LIS.size();
    int mid = (start + end) / 2;
    
    while(start < end) {
        mid = (start + end) / 2;
        
        if(LIS[mid] < n) { start = mid + 1; }
        else { end = mid; }
    }
    
    return end;
}
