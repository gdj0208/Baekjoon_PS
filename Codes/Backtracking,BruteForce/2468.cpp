#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>

using namespace std;

class MainClass {
public:
    void run();
private:
    int map[100][100];
    bool visit[100][100];
    int size, max_height;
    int add_x[4] = {0,0,-1,1};  //상하좌우
    int add_y[4] = {-1,1,0,0};
    
    void init_maze();
    void init_visit();
    void bfs();
    int small_bfs(int x, int y, int height);
    void print_maze();
    bool is_in_range(int x, int y);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init_maze();
    //print_maze();
    bfs();
}

void MainClass::init_maze() {
    int data;
    
    cin >> size;
    max_height = 0;
    
    for(int y = 0; y < size; y++) {
        getchar();
        for(int x = 0; x < size; x++) {
            scanf("%d", &data);
            max_height = (data > max_height) ? data : max_height;
            map[y][x] = data;
        }
    }
}

void MainClass::init_visit() {
    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) { visit[y][x] = false; }
    }
}

void MainClass::print_maze() {
    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) { cout << map[y][x]; }
        cout << "\n";
    }
}

void MainClass::bfs() {
    list<int> town;
    int number_of_islands = 0;
    int max_number_of_islands = 0;
    
    for(int height = 0; height < max_height; height++) {
        init_visit();
        number_of_islands = 0;
        
        for(int y = 0; y < size; y++) {
            for(int x = 0; x < size; x++) {
                if(map[y][x] > height and visit[y][x] == false) {
                    small_bfs(x, y, height);
                    number_of_islands++;
                }
            }
        }
        
        max_number_of_islands = (max_number_of_islands > number_of_islands) ? max_number_of_islands : number_of_islands;
    }
    
    cout << max_number_of_islands;
}

int MainClass::small_bfs(int x, int y, int height) {
    list<pair<int, int>> check_list, tmp;
    int next_x, next_y;
    int count = 0;
    
    tmp.push_back(make_pair(y, x));
    
    while(!tmp.empty()) {
        check_list = tmp;
        tmp.clear();
        
        while(!check_list.empty()) {
            y = check_list.front().first;
            x = check_list.front().second;
            check_list.pop_front();
            
            if(visit[y][x] == true) { continue; }
            
            visit[y][x] = true;
            
            for(int i = 0; i < 4; i++) {
                next_x = x + add_x[i];
                next_y = y + add_y[i];
                
                if(!is_in_range(next_x, next_y)) { continue; }
                
                if(map[next_y][next_x] > height and visit[next_y][next_x] == false) { tmp.push_back(make_pair(next_y, next_x)); }
            }
        }
    }
    
    return count;
}

bool MainClass::is_in_range(int x, int y) { return 0 <= x and x < size and 0 <= y and y < size; }
