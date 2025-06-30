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
    list<int> li, tmp;
    
    int** board;
    int board_width, board_height;
    int end_x, end_y;
    int start_x, start_y;
    int count;
    
    void initBoard();
    void time_passes();
    bool leftAvailable(int loc);
    bool rightAvailable(int loc);
    bool upAvailable(int loc);
    bool downAbailabe(int loc);
    void printBoard();
    bool isLeft();
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
    //printBoard();
    time_passes();
    //printBoard();
    
    if(isLeft()) { cout << -1; }
    else { cout << count; }
    //printCountBoard();
}

void MainClass::initBoard() {
    int ver;
    cin >> board_width >> board_height;
    
    end_x = board_width - 1;
    end_y = board_height - 1;
    
    board = (int**)calloc(sizeof(int*), board_height);
    for(int i = 0; i < board_height; i++) { board[i] = (int*)calloc(sizeof(int), board_width); }
    
    for(int y = 0; y < board_height; y++) {
        for(int x = 0; x < board_width; x++) {
            scanf("%d", &board[y][x]);
            if(board[y][x] == 1) { tmp.push_back(y * board_width + x); }
            //cin >> board[y][x];
        }
    }
}


void MainClass::time_passes() {
    bool *p;
    int p_loc = 0;
    int x, y;
    count = -1;
    
    p_loc = start_y * board_width + start_x;
    tmp.push_back(p_loc);
    
    while(!li.empty() or !tmp.empty()) {
        
        li = tmp;
        tmp.clear();
        
        count++;
        //printBoard();
        while(!li.empty()) {
            
            p_loc = li.front();
            li.pop_front();
            
            
            y = p_loc / board_width;
            x = p_loc % board_width;
            
            if(board[y][x] == 1) {
                
                if(leftAvailable(p_loc)) {
                    board[y][x-1] = 1;
                    tmp.push_back(p_loc - 1);
                }
                if(rightAvailable(p_loc)) {
                    board[y][x + 1] = 1;
                    tmp.push_back(p_loc + 1);
                }
                if(upAvailable(p_loc)) {
                    board[y - 1][x] = 1;
                    tmp.push_back(p_loc - board_width);
                }
                if(downAbailabe(p_loc)) {
                    board[y + 1][x] = 1;
                    tmp.push_back(p_loc + board_width);
                }
            }
            
        }
    }
}

bool MainClass::leftAvailable(int loc) {
    int x = loc % board_width;
    int y = loc / board_width;
    
    return x > 0 and board[y][x - 1] == 0;
}

bool MainClass::rightAvailable(int loc) {
    int x = loc % board_width;
    int y = loc / board_width;
    
    return x < board_width - 1 and board[y][x + 1] == 0;
}

bool MainClass::upAvailable(int loc) {
    int x = loc % board_width;
    int y = loc / board_width;
    return y > 0 and board[y - 1][x] == 0;
}

bool MainClass::downAbailabe(int loc) {
    int x = loc % board_width;
    int y = loc / board_width;
    
    //cout << board[y + 1][x] << endl;
    
    return y < board_height - 1 and board[y + 1][x] == 0;
}

void MainClass::printBoard() {
    cout << endl;
    for(int y = 0; y < board_height; y++) {
        for(int x = 0; x < board_width; x++) {
            cout << board[y][x] << " ";
        }
        cout << endl;
    }
}
bool MainClass::isLeft() {
    for(int y = 0; y <board_height; y++) {
        for(int x = 0; x < board_width; x++) { if(board[y][x] == 0) { return true; } }
    }
    return false;
}