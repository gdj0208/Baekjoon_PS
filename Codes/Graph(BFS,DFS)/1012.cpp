#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
#include <unordered_map>

using namespace std;
#define null NULL

/* ----- [ 클래스 ] ---------------------------------------------------------------- */

class MainClass{
public:
    void run();
private:
    int test_case;
    int width, height;
    int number_of_worm, worms_in_need;
    int **farm;
    
    void init_farm();
    int find_worms_in_need();
    void DFS(int x, int y);
};

/* ----- [ 기타 함수 ] -------------------------------------------------------------- */


/* ----- [ 메인 함수 ] -------------------------------------------------------------- */
int main() {
    srand(time(NULL));
    
    MainClass* mainClass = new MainClass();
    mainClass->run();
    delete mainClass;
}

/* ----- [ 클래스 ] ---------------------------------------------------------------- */

void MainClass::run() {
    int x, y;
    
    cin >> test_case;       // 테스트 케이스 횟수 입력
    
    // 테스트 케이스 실행
    while(test_case--) {
        
        // 농장의 정보와 벌래의 수 입력
        cin >> width >> height >> number_of_worm;
        
        // 농장 초기화
        init_farm();
        
        // 배추들 위치 입력받기
        while (number_of_worm--) {
            cin >> x >> y;
            farm[y][x] = 1;
        }
        
        worms_in_need = find_worms_in_need();
        cout << worms_in_need << endl;
    }
}

void MainClass::init_farm() {
    farm = (int**)calloc(height, sizeof(int*));
    for(int i = 0; i < height; i++) { farm[i] = (int*)calloc(width, sizeof(int)); }
    
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) { farm[y][x] = 0; }
    }
}

int MainClass::find_worms_in_need() {
    int count = 0;
    
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            if( farm[y][x] == 1 ) { DFS(x, y); count += 1; }
        }
    }
    
    return count;
}

void MainClass::DFS(int x, int y) {
    int loc = y * width + x;
    
    if(farm[y][x] == 0) { return; }
    
    farm[y][x] = 0;
    
    if(0 < y) { DFS(x, y - 1); }             // 윗칸 조사
    if(0 < x) { DFS(x - 1, y); }             // 왼쪽 칸 조사
    if(x + 1 < width) { DFS(x + 1, y); }    // 오른쪽 칸 조사
    if(y + 1 < height) { DFS(x, y + 1); }   // 아랫칸 조사
}

/* ----- [ 기타 함수 ] -------------------------------------------------------------- */

/*
 */
