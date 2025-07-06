#include <iostream>
#include <algorithm>
#include <cstring>
#include <list>
#include <unordered_set>

#define ll long long
#define INF 2000000000

using namespace std;

class MainClass {
public:
    void run();
    
private:
    vector<int> arr;
    int diff_req;
    
    void init_data();
    int get_min_diff();
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init_data();
    cout << get_min_diff();
}

void MainClass::init_data() {
    int arr_size, tmp;
    
    cin >> arr_size >> diff_req;
    while(arr_size--) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    sort(arr.begin(), arr.end());
}

int MainClass::get_min_diff() {
    int start(0), end(0);
    int min_diff(INF), dif;
    
    while(start < arr.size() and end < arr.size()) {
        
        dif = abs(arr[end] - arr[start]);
        if(diff_req <= dif and dif < min_diff) { min_diff = dif; }
        
        if(dif < diff_req) { end++; }
        else if(dif > diff_req) { start++; }
        else if(dif == diff_req) { return dif; }
    }
    
    return min_diff;
}

/*
 5 3
 1 2 3 4 5
 3
 
 7 4
 1 8 15 16 17 18 22
 4
 
 5 6
 1 2 3 4 11
 7
 */
