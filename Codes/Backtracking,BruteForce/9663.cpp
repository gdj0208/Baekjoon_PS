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
    int *y_location_of_queen;
    bool *y_location_used;
    int number_of_queen;
    int count;
    
    void locate_queen(int num);
    void init_y_infos();
    bool check_diagnol(int num_of_queen);           // /    방향 대각선
    bool check_rev_diagnol(int num_of_queen);       // \ 방향 대각선
    
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    count = 0;
    
    cin >> number_of_queen;
    init_y_infos();
    locate_queen(0);
    cout << count;
}

void MainClass::locate_queen(int num) {
    if(num == number_of_queen) { count++; }
    
    for(int i = 0; i < number_of_queen; i++) {
        if(y_location_used[i]) { continue; }
        
        y_location_of_queen[num] = i;
        
        // 모든 대각선 조건을 달성한 경우
        if(check_diagnol(num) and check_rev_diagnol(num)) {
            y_location_used[i] = true;
            locate_queen(num + 1);
            y_location_used[i] = false;
        }
        else { y_location_of_queen[num] = -1; }
    }
}

void MainClass::init_y_infos() {
    y_location_of_queen = new int[number_of_queen];
    for(int i = 0; i < number_of_queen; i++) { y_location_of_queen[i] = -1; }
    
    y_location_used = new bool[number_of_queen];
    for(int i = 0; i < number_of_queen; i++) { y_location_used[i] = false; }
}

bool MainClass::check_diagnol(int num_of_queen) {
    for(int i = 0; i < num_of_queen; i++) {
        if(y_location_of_queen[i] + i == y_location_of_queen[num_of_queen] + num_of_queen) { return false; }
    }
    return true;
}
bool MainClass::check_rev_diagnol(int num_of_queen) {
    for(int i = 0; i < num_of_queen; i++) { 
        if(y_location_of_queen[i] - i == y_location_of_queen[num_of_queen] - num_of_queen) { return false; }
    }
    return true;
}
