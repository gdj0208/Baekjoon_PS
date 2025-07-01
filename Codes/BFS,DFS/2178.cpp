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
    int** count_board;
    int board_width, board_height;
    int end_x, end_y;
    
    void initBoard();
    void findBiggest();
    bool leftAvailable(int loc);
    bool rightAvailable(int loc);
    bool upAvailable(int loc);
    bool downAbailabe(int loc);
    void printCountBoard();
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
    cout << count_board[board_height - 1][board_width - 1];
    
    //printCountBoard();
}

void MainClass::initBoard() {
    int ver;
    cin >> board_height >> board_width;
    
    end_x = board_width - 1;
    end_y = board_height - 1;
    
    board = (bool**)calloc(sizeof(bool*), board_height);
    count_board = (int**)calloc(sizeof(int*), board_height);
    
    for(int i = 0; i < board_height; i++) { board[i] = (bool*)calloc(sizeof(bool), board_width); }
    for(int i = 0; i < board_height; i++) { count_board[i] = (int*)calloc(sizeof(int), board_width); }
    
    for(int y = 0; y < board_height; y++) {
        for(int x = 0; x < board_width; x++) {
            scanf("%1d", &board[y][x]);
            //cin >> board[y][x];
            count_board[y][x] = 0;
        }
    }
}


void MainClass::findBiggest() {
    list<int> li, tmp;
    bool *p;
    int p_loc = 0;
    int x, y;
    int count = 0;
    
    tmp.push_back(p_loc);
    
    while(!li.empty() or !tmp.empty()) {
        
        li = tmp;
        tmp.clear();
        
        count++;
        
        while(!li.empty()) {
            
            p_loc = li.front();
            li.pop_front();
            y = p_loc / board_width;
            x = p_loc % board_width;
            
            if(board[y][x] == 1) {
                if(count_board[y][x] == 0) { count_board[y][x] = count; }
                
                if(leftAvailable(p_loc)) {
                    tmp.push_back(p_loc - 1);
                }
                if(rightAvailable(p_loc)) {
                    tmp.push_back(p_loc + 1);
                }
                if(upAvailable(p_loc)) {
                    tmp.push_back(p_loc - board_width);
                }
                if(downAbailabe(p_loc)) {
                    tmp.push_back(p_loc + board_width);
                }
                
                board[y][x] = 0;
            }
            
        }
    }
}

bool MainClass::leftAvailable(int loc) {
    int x = loc % board_width;
    int y = loc / board_width;
    
    return x > 0 and board[y][x - 1] == 1;
}

bool MainClass::rightAvailable(int loc) {
    int x = loc % board_width;
    int y = loc / board_width;
    
    return x < board_width - 1 and board[y][x + 1] == 1;
}

bool MainClass::upAvailable(int loc) {
    int x = loc % board_width;
    int y = loc / board_width;
    return y > 0 and board[y - 1][x] == 1;
}

bool MainClass::downAbailabe(int loc) {
    int x = loc % board_width;
    int y = loc / board_width;
    
    //cout << board[y + 1][x] << endl;
    
    return y < board_height - 1 and board[y + 1][x] == 1;
}

void MainClass::printCountBoard() {
    cout << endl;
    for(int y = 0; y < board_height; y++) {
        for(int x = 0; x < board_width; x++) {
            cout << count_board[y][x] << " ";
        }
        cout << endl;
    }
}