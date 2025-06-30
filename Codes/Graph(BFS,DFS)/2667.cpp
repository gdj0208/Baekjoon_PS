#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>

#define street 0
#define building 1

using namespace std;

class MainClass {
public:
    void run();
private:
    bool map[25][25];
    int size;
    int add_x[4] = {0,0,-1,1};  //상하좌우
    int add_y[4] = {-1,1,0,0};
    
    void init_maze();
    void bfs();
    int small_bfs(int x, int y);
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
    
    for(int y = 0; y < size; y++) {
        getchar();
        for(int x = 0; x < size; x++) { scanf("%1d", &data); map[y][x] = (data == 1) ? true : false; }
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
    int number_of_buildings;
    
    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) {
            if(map[y][x] == building) {
                number_of_buildings = small_bfs(x, y);
                town.push_back(number_of_buildings);
            }
        }
    }
    
    town.sort();
    
    cout << town.size() << "\n";
    for(auto t : town) { cout << t << "\n"; }
}

int MainClass::small_bfs(int x, int y) {
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
            
            if(map[y][x] == street) { continue; }
            
            map[y][x] = street;
            count++;
            
            for(int i = 0; i < 4; i++) {
                next_x = x + add_x[i];
                next_y = y + add_y[i];
                
                if(!is_in_range(next_x, next_y)) { continue; }
                
                if(map[next_y][next_x] == building) { tmp.push_back(make_pair(next_y, next_x)); }
            }
        }
    }
    
    return count;
}

bool MainClass::is_in_range(int x, int y) { return 0 <= x and x < size and 0 <= y and y < size; }
