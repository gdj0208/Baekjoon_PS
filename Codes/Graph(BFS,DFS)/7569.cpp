#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>

#define riped 1
#define raw 0
#define none -1

using namespace std;

class MainClass {
public:
    void run();
private:
    int width_x, width_y, width_z;
    int graph[100][100][100];
    bool visited[100][100][100] = {0};
    //  상 하 좌 우 앞 뒤
    int adjacent_z[6] = {1, -1, 0, 0, 0, 0};
    int adjacent_y[6] = {0, 0, 0, 0, 1, -1};
    int adjacent_x[6] = {0, 0, -1, 1, 0, 0};
    int day;
    bool all_riped;
    
    void init_graph();
    void print_graph();
    void proceed();
    bool chek_all_riped();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init_graph();
    //print_graph();
    proceed();
    
    all_riped = chek_all_riped();
    
    if(all_riped) {
        //if(day == 1) {cout << day;}
        //else { cout << day - 1; }
        cout << day - 1;
    }
    else { cout << -1; }
}

void MainClass::init_graph() {
   // all_riped = true;
    
    cin >> width_x >> width_y >> width_z;
    
    for(int z = 0; z < width_z; z++) {
        for(int y = 0; y < width_y; y++) {
            for(int x = 0; x < width_x; x++) {
                cin >> graph[z][y][x];
                //if(graph[z][y][x] == raw) { all_riped = false; }
            }
        }
    }
}

void MainClass::print_graph() {
    for(int z = 0; z < width_z; z++) {
        for(int y = 0; y < width_y; y++) {
            for(int x = 0; x < width_x; x++) {
                cout << graph[z][y][x] << " ";
            }
            cout << "\n";
        }
    }
}

void MainClass::proceed() {
    list<tuple<int, int ,int>> find_list, tmp;
    int tmp_x, tmp_y, tmp_z, loc;
    int next_x, next_y, next_z;
    
    day = 0;
    
    for(int z = 0; z < width_z; z++) {
        for(int y = 0; y < width_y; y++) {
            for(int x = 0; x < width_x; x++) {
                if(graph[z][y][x] == riped) { tmp.push_back(make_tuple(z,y,x)); }
            }
        }
    }
    
    
    while(!tmp.empty()) {
        find_list = tmp;
        tmp.clear();
        
        while(!find_list.empty()) {
            tmp_z = get<0>(find_list.front());
            tmp_y = get<1>(find_list.front());
            tmp_x = get<2>(find_list.front());
            find_list.pop_front();
            
            if(graph[tmp_z][tmp_y][tmp_x] == none) { continue; }
            
            for(int i = 0; i < 6; i++) {
                next_z = tmp_z + adjacent_z[i];
                next_y = tmp_y + adjacent_y[i];
                next_x = tmp_x + adjacent_x[i];
                
                if(next_z < 0 or next_z >= width_z) { continue; }
                if(next_y < 0 or next_y >= width_y) { continue; }
                if(next_x < 0 or next_x >= width_x) { continue; }
                
                if(graph[next_z][next_y][next_x] == raw) {
                    graph[next_z][next_y][next_x] = riped;
                    tmp.push_back(make_tuple(next_z, next_y, next_x));
                }
            }
        }
        
        day++;
        //cout << "day : " << day << "\n";
        //print_graph();
    }
}

bool MainClass::chek_all_riped() {
    for(int z = 0; z < width_z; z++) {
        for(int y = 0; y < width_y; y++) {
            for(int x = 0; x < width_x; x++) {
                if(graph[z][y][x] == raw) { return false; }
            }
        }
    }
    return true;
}