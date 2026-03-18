#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <math.h>
#include <time.h>

#define size 15

using namespace std;

class MainClass {
public:
    void run();
private:
    int arr[20];
    bool used[20] = {0};
    int size_of_arr;
    int sum, count, ans;
    
    void get_arr();
    void get_ans();
    void get_case(int latest_used_loc, int level, int size_of_sub_arr);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    count = sum =0;
    get_arr();
    get_ans();
    cout << count;
}

void MainClass::get_arr() {
    cin >> size_of_arr >> ans;
    for(int i = 0; i <size_of_arr; i++) { cin >> arr[i]; }
}

void MainClass::get_ans() {
    int size_of_sub_arr = 1;
    int size_of_used_sub = 0;
    
    while(size_of_sub_arr <= size_of_arr) {
        // 부분수열의 크기에 따라 합을 구하는 부분수열 찾기
        get_case(-1, 0, size_of_sub_arr);
        size_of_sub_arr++;
    }
}

void MainClass::get_case(int latest_used_loc, int level, int size_of_sub_arr) {
    if(level == size_of_sub_arr) {
        if(sum == ans) { count++; }
        return;
    }
    
    for(int i = latest_used_loc + 1; i < size_of_arr; i++) {
        if(used[i]) { continue; }
        
        used[i] = true;
        sum += arr[i];
        
        get_case(i, level + 1, size_of_sub_arr);
        
        used[i] = false;
        sum -= arr[i];
    }
}
