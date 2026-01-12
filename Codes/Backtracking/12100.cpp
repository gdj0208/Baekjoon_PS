#include <iostream>
#include <algorithm>
#include <cstring>
#include <list>
#include <unordered_set>

#define ll long long

using namespace std;

class MainClass {
public:
    void run();
    
private:
    vector<vector<int>>arr;
    int size;
    int max = 0;
    int rpt = 5;
    
    void init_arr();
    void push_left(vector<vector<int>>* copy);
    void push_right(vector<vector<int>>* copy);
    void push_up(vector<vector<int>>* copy);
    void push_down(vector<vector<int>>* copy);
    void run_all_cases(vector<vector<int>>, int repeat);
    void print_arr(vector<vector<int>>* copy);
    int get_max(vector<vector<int>>*copy);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init_arr();
    run_all_cases(arr, rpt);
    cout << max;
}

void MainClass::init_arr() {
    cin >> size;
    
    arr.resize(size);
    for(int i = 0; i < size; i++) { arr[i].resize(size, 0); }
    
    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) { cin >> arr[y][x]; }
    }
}

void MainClass::push_left(vector<vector<int>> *copy) {
    for(int y = 0; y < size; y++) {
        int index = 0; // 숫자를 채울 위치
        for (auto num : (*copy)[y]) {
            if (num != 0) { (*copy)[y][index++] = num;  }
        }
        // 나머지 공간은 0으로 채움
        while (index < (*copy)[y].size()) {
            (*copy)[y][index++] = 0;
        }
    }
    
    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size-1; x++) {
            if((*copy)[y][x] == (*copy)[y][x+1]) { (*copy)[y][x] *= 2; (*copy)[y][x+1] = 0; }
        }
    }
    
    for(int y = 0; y < size; y++) {
        int index = 0; // 숫자를 채울 위치
        for (auto num : (*copy)[y]) {
            if (num != 0) { (*copy)[y][index++] = num;  }
        }
        // 나머지 공간은 0으로 채움
        while (index < (*copy)[y].size()) {
            (*copy)[y][index++] = 0;
        }
    }
}

void MainClass::push_right(vector<vector<int>> *copy) {
    for(int y = 0; y < size; y++) {
        int index = size - 1; // 숫자를 채울 위치
        for (int i = size - 1; i >= 0; i--) {
            if ((*copy)[y][i] != 0) { (*copy)[y][index--] = (*copy)[y][i]; }
        }
        // 나머지 공간은 0으로 채움
        while (index >= 0) {
            (*copy)[y][index--] = 0;
        }
    }
    
    for(int y = 0; y < size; y++) {
        for(int x = size-1; x > 0; x--) {
            if((*copy)[y][x] == (*copy)[y][x-1]) { (*copy)[y][x] *= 2; (*copy)[y][x-1] = 0; }
        }
    }
    
    for(int y = 0; y < size; y++) {
        int index = size - 1; // 숫자를 채울 위치
        for (int i = size - 1; i >= 0; i--) {
            if ((*copy)[y][i] != 0) { (*copy)[y][index--] = (*copy)[y][i]; }
        }
        // 나머지 공간은 0으로 채움
        while (index >= 0) {
            (*copy)[y][index--] = 0;
        }
    }
}

void MainClass::push_up(vector<vector<int>> *copy) {
    for(int x = 0; x < size; x++) {
        int index = 0; // 숫자를 채울 위치
        for (int y = 0; y < size; y++) {
            if ((*copy)[y][x] != 0) { (*copy)[index++][x] = (*copy)[y][x]; }
        }
        // 나머지 공간은 0으로 채움
        while (index < size) {
            (*copy)[index++][x] = 0;
        }
    }
    
    for(int x = 0; x < size; x++) {
        for(int y = 0; y < size-1; y++) {
            if((*copy)[y][x] == (*copy)[y+1][x]) { (*copy)[y][x] *= 2; (*copy)[y+1][x] = 0; }
        }
    }
    
    for(int x = 0; x < size; x++) {
        int index = 0; // 숫자를 채울 위치
        for (int y = 0; y < size; y++) {
            if ((*copy)[y][x] != 0) { (*copy)[index++][x] = (*copy)[y][x]; }
        }
        // 나머지 공간은 0으로 채움
        while (index < size) {
            (*copy)[index++][x] = 0;
        }
    }
}

void MainClass::push_down(vector<vector<int>> *copy) {
    for(int x = 0; x < size; x++) {
        int index = size - 1; // 숫자를 채울 위치
        for (int y = size - 1; y >= 0; y--) {
            if ((*copy)[y][x] != 0) { (*copy)[index--][x] = (*copy)[y][x]; }
        }
        // 나머지 공간은 0으로 채움
        while (index >= 0) {
            (*copy)[index--][x] = 0;
        }
    }
    
    for(int x = 0; x < size; x++) {
        for(int y = size-1; y > 0; y--) {
            if((*copy)[y-1][x] == (*copy)[y][x]) { (*copy)[y][x] *= 2; (*copy)[y-1][x] = 0; }
        }
    }
    
    for(int x = 0; x < size; x++) {
        int index = size - 1; // 숫자를 채울 위치
        for (int y = size - 1; y >= 0; y--) {
            if ((*copy)[y][x] != 0) { (*copy)[index--][x] = (*copy)[y][x]; }
        }
        // 나머지 공간은 0으로 채움
        while (index >= 0) {
            (*copy)[index--][x] = 0;
        }
    }
}

void MainClass::run_all_cases(vector<vector<int>>copy, int repeat) {
    if(repeat == 0) {
        int new_max = get_max(&copy);
        max = (new_max > max) ? new_max : max;
        //print_arr(&copy);
        return;
    }
    
    vector<vector<int>> edit;
    
    /*
     1. 상, 하, 좌, 우로 한 번씩 옮겨봄
     3. 옮겨본 후에 run_all_cases 실행
     */
    
    edit = copy;
    push_left(&edit);
    //print_arr(&edit);
    run_all_cases(edit, repeat-1);
    
    edit = copy;
    push_right(&edit);
    //print_arr(&edit);
    run_all_cases(edit, repeat-1);
    
    edit = copy;
    push_up(&edit);
    //print_arr(&edit);
    run_all_cases(edit, repeat-1);
    
    edit = copy;
    push_down(&edit);
    //print_arr(&edit);
    run_all_cases(edit, repeat-1);
}

void MainClass::print_arr(vector<vector<int>>*copy) {
    cout << "\n";
    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) { cout << (*copy)[y][x] << " "; }
        cout << "\n";
    }
}

int MainClass::get_max(vector<vector<int>>*copy) {
    int new_max =0;
    for(int x = 0; x < size; x++) {
        for(int y = 0; y < size; y++) {
            new_max = ((*copy)[y][x] > new_max) ? (*copy)[y][x] : new_max;
        }
    }
    return new_max;
}

/*
 4
 2 4 16 8
 8 4 0 0
 16 8 2 0
 2 8 2 0
 */
