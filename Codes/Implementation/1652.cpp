#include <iostream>
#include <stdlib.h>
//#include <string.h>
//#include <time.h>

#define null NULL

using namespace std;

/* ----- [ 클래스 ] ---------------------------------------------------------------- */
class Finder{
public:
    int size, verCount, horCount;
    bool **board;
    
    void run();
    
private:
    void makeBoard();
    void countVer();
    void countHor();
    void getBoard();
    void printBoard();
};

/* ----- [ 기타 함수 ] -------------------------------------------------------------- */

/* ----- [ 메인 함수 ] -------------------------------------------------------------- */
int main() {
    
    Finder *finder;
    finder = new Finder;
    
    finder->run();
    
    delete finder;
}

/* ----- [ 클래스 ] ---------------------------------------------------------------- */
void Finder::run() {
    verCount = 0;
    horCount = 0;
    
    makeBoard();
    //printBoard();
    
    countHor();
    countVer();
    
    cout << horCount << " " << verCount;
}
void Finder::countHor() {
    int x, y, cnt;
    
    for(y = 0; y < size; y++) {
        cnt = 0;
        
        for(x = 0; x < size; x++) {
            if(!board[y][x]) {
                if(cnt >= 2) { horCount++; }
                cnt = 0;
            }
            else { cnt++; }
        }
        if(cnt >= 2) { horCount++; }
    }
}
void Finder::countVer() {
    int x, y, cnt;
    
    for(x = 0; x < size; x++) {
        cnt = 0;
        
        for(y = 0; y < size; y++) {
            if(!board[y][x]) {
                if(cnt >= 2) { verCount++; }
                cnt = 0;
            }
            else { cnt++; }
        }
        
        if(cnt >= 2) { verCount++; }
    }
}
void Finder::makeBoard() {
    char tmp;
    int x, y;
    
    cin >> size;
    
    board = (bool**)calloc(size , sizeof(bool*));
    if(board == NULL) { printf("allocation failed!\n"); return; }
    
    for(y = 0; y < size; y++) {
        board[y] = (bool*)calloc(size, sizeof(bool));
        if(board[y] == NULL) { printf("allocation failed!\n"); return; }
    }
    
    for(y = 0; y < size; y++) {
        for(x = 0; x < size; x++) {
            cin >> tmp;
            
            if(tmp == '.') { board[y][x] = 1; }
            else{ board[y][x] = 0; }
        }
    }
}
void Finder::printBoard() {
    int x, y;
    
    for(y = 0; y < size; y++) {
        for(x = 0; x < size; x++){
            if(board[y][x]) {cout << "◻︎";}
            else { cout << "◼︎"; }
        }
        cout << endl;
    }
}