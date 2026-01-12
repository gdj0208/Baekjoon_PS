#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>

#define start 'S'
#define end 'E'
#define space '.'
#define wall '#'

using namespace std;

class MainClass {
public:
    void run();
private:
    char building[30][30][30];
    int width_z, width_x, width_y;
    int add_x[6] = {0, 0, -1 ,1 ,0, 0};    // 상 하 좌 우 앞 뒤
    int add_y[6] = {0, 0, 0, 0, 1, -1};
    int add_z[6] = {-1, 1, 0, 0, 0, 0};
    
    void init_building();
    void print_building();
    void bfs();
    bool is_end();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    while(1) {
        init_building();
        if(is_end()) { break; }
        
        //print_building();
        bfs();
    }
}

void MainClass::init_building() {
    
    cin >> width_z >> width_y >> width_x;
    
    for(int z = 0; z < width_z; z++) {
        for(int y = 0; y < width_y; y++) {
            getchar();
            for(int x = 0; x < width_x; x++) { scanf("%c", &building[z][y][x]); }
        }
        getchar();
    }
}

void MainClass::print_building() {
    cout << "\n";
    
    for(int z = 0; z < width_z; z++) {
        for(int y = 0; y < width_y; y++) {
            for(int x = 0; x < width_x; x++) { cout << building[z][y][x]; }
            cout << "\n";
        }
    }
}

bool MainClass::is_end() { return width_x == width_y and width_y == width_z and width_z == 0; }

void MainClass::bfs() {
    list<tuple<int, int, int>> check_list, tmp;
    bool loc_initiated = false;
    bool find_end = false;
    
    int count = 0;
    int now_x, now_y, now_z;
    int next_x, next_y, next_z;
    
    for(int z = 0; z < width_z and loc_initiated == false; z++) {
        for(int y = 0; y < width_y and loc_initiated == false; y++) {
            for(int x = 0; x < width_x and loc_initiated == false; x++) {
                if(building[z][y][x] == start) {
                    tmp.push_back(make_tuple(z,y,x));
                    loc_initiated = true;
                }
            }
        }
    }
    
    while(!tmp.empty() and !find_end) {
        check_list = tmp;
        tmp.clear();
        
        while(!check_list.empty() and !find_end) {
            now_z = get<0>(check_list.front());
            now_y = get<1>(check_list.front());
            now_x = get<2>(check_list.front());
            check_list.pop_front();
            
            for(int i = 0; i < 6; i++) {
                next_x = now_x + add_x[i];
                next_y = now_y + add_y[i];
                next_z = now_z + add_z[i];
                
                if(next_z < 0 or width_z <= next_z or next_y < 0 or width_y <= next_y or next_x < 0 or width_x <= next_x) { continue; }
                
                if(building[next_z][next_y][next_x] == end) { find_end = true; break; }
                else if(building[next_z][next_y][next_x] == space) {
                    building[next_z][next_y][next_x] = wall;
                    tmp.push_back(make_tuple(next_z, next_y, next_x));
                }
            }
        }
        
        count++;
    }
    
    if(find_end) { cout << "Escaped in " << count << " minute(s).\n"; }
    else { cout << "Trapped!\n"; }
}

/*
1 3 3
#S#
#E#
###
 */
