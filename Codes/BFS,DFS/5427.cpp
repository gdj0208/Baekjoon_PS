#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>

#define person '@'
#define fire '*'
#define space '.'
#define wall '#'

using namespace std;

class MainClass {
public:
    void run();
private:
    char maze[1000][1000];
    int hor, ver, rpt;
    int add_x[4] = {0,0,-1,1};  //상하좌우
    int add_y[4] = {-1,1,0,0};
    
    void init_maze();
    void bfs();
    void print_maze();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    cin >> rpt;
    while(rpt--) {
        init_maze();
        //print_maze();
        bfs();
    }
}

void MainClass::init_maze() {
    cin >> hor >> ver;
    
    for(int y = 0; y < ver; y++) {
        getchar();
        for(int x = 0; x < hor; x++) { scanf("%c", &maze[y][x]); }
    }
}

void MainClass::print_maze() {
    for(int y = 0; y < ver; y++) {
        for(int x = 0; x < hor; x++) { cout << maze[y][x]; }
        cout << "\n";
    }
}

void MainClass::bfs() {
    list<tuple<int, int, char>> check_list, tmp;
    bool escaped = false;
    char type;
    int x,y;
    int next_x, next_y;
    int count = 0;
    
    for(y = 0; y < ver; y++) {
        for(x = 0; x < hor; x++) {
            if(maze[y][x] == person) { tmp.push_back(make_tuple(y, x, maze[y][x])); }
            else if(maze[y][x] == fire) { tmp.push_front(make_tuple(y, x, maze[y][x])); }
        }
    }
    
    while(!tmp.empty() and !escaped) {
        check_list = tmp;
        tmp.clear();
        
        while(!check_list.empty() and !escaped) {
            y = get<0>(check_list.front());
            x = get<1>(check_list.front());
            type = get<2>(check_list.front());
            //type = maze[y][x];
            check_list.pop_front();
            
            for(int i = 0; i < 4; i++) {
                next_x = x + add_x[i];
                next_y = y + add_y[i];
                
                if(next_x < 0 or hor == next_x or next_y < 0 or ver == next_y) {
                    if(type == person) { escaped = true; break; }
                    else { continue; }
                }
                if(maze[next_y][next_x] == wall) { continue; }
                
                if(type == person) {
                    if(maze[next_y][next_x] == space) {
                        maze[next_y][next_x] = person;
                        tmp.push_back(make_tuple(next_y, next_x, person));
                    }
                }
                else if(type == fire) {
                    if(maze[next_y][next_x] == space or maze[next_y][next_x] == person) {
                        maze[next_y][next_x] = fire;
                        tmp.push_front(make_tuple(next_y, next_x, fire));
                    }
                }
            }
        }
        
        count++;
    }
    
    if(escaped) { cout << count << "\n"; }
    else { cout << "IMPOSSIBLE" << "\n"; }
}