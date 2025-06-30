#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <time.h>

using namespace std;
#define null NULL

/* ----- [ 클래스 ] ---------------------------------------------------------------- */


class MainClass{
public:
    void run();
private:
    bool** board;
    int board_width, board_height;
    
    void initBoard();
    void findBiggest();
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
    initBoard();
    findBiggest();
}

void MainClass::initBoard() {
    int ver;
    cin >> board_height >> board_width;
    
    board = (bool**)calloc(sizeof(bool*), board_height);
    for(int i = 0; i < board_height; i++) { board[i] = (bool*)calloc(sizeof(bool), board_width); }
    
    for(int y = 0; y < board_height; y++) {
        for(int x = 0; x < board_width; x++) {
            cin >> board[y][x];
        }
    }
}


void MainClass::findBiggest() {
    int num, area, max_area,loc;
    bool *vertic;
    list<int> draw;
    
    num = max_area = area = 0;
    
    for(int y = 0; y < board_height; y++) {
        for(int x = 0; x <board_width; x++) {
            // 빈 공간일 경우 생략
            if(board[y][x] == 0) { continue; }
            
            /*
             0. num++
             1. draw에 해당 칸 넣기
             3. draw가 빌 때 까지 반복
                1. 해당 칸 = 0
                1. draw 첫 칸의 상하좌우가 1이면 draw에 추가
                2. area++
             */
            
            //if(draw.size() == 0) { num++; }
            num++;
            draw.push_back(board_width * y + x);
            
            while(draw.size() != 0) {
                loc = draw.front();
                draw.pop_front();
                
                vertic = &board[loc/board_width][loc%board_width];
                
                if( *vertic == 0) { continue; }
                *vertic = 0;
                
                // 상
                if(loc/board_width > 0 and board[loc/board_width - 1][loc%board_width] == 1) {
                    draw.push_back(loc - board_width);
                }
                
                // 하
                if(loc/board_width < board_height - 1 and board[loc/board_width + 1][loc%board_width] == 1) {
                    draw.push_back(loc + board_width);
                }
                
                // 좌
                if(loc%board_width > 0 and board[loc/board_width][loc%board_width - 1] == 1) {
                    draw.push_back(loc - 1);
                }
                
                // 우
                if(loc%board_width < board_width - 1 and board[loc/board_width][loc%board_width + 1] == 1) {
                    draw.push_back(loc + 1);
                }
                
                area++;
            }
            
            max_area = (area > max_area) ? area : max_area;
            area = 0;
        }
    }
    
    cout << num << endl << max_area << endl;
}
