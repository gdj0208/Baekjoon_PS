#include <iostream>
#include <algorithm>
#include <limits>
#include <list>

#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b
#define x first
#define y second

using namespace std;

class MainClass {
public:
    void run();
    
private:
    int num_of_buildings;
    int max;
    vector<int>height, visible_buildings;
    
    void init_building_infos();
    int get_visible_building(int building_num);
    pair<double, double>get_inc_and_cons(pair<int, int>p1, pair<int,int>p2);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    /*
     풀이방법
     1. 빌딩의 위치와 높이를 입력받고 이를 좌표계로 표현한다.
     2. 모든 점들을 대상으로 시작점과 종점을 할당한다.
     3. 시작점이 되는 빌딩의 좌표와 종점이 되는 빌딩의 좌표를 선분으로 긋는다.
     4. 시작점과 종점 사이 모든 정점들에 대해서 y값이 2.의 선분보다 위에 있는지 확인하여 두 빌딩이 서로 볼 수 있는지 확인한다.
     */
    
    // 빌딩들의 위치와 높이를 입력받고 이를 좌표계로 표현
    init_building_infos();
    
    // 가장 많이 보이는 빌딩의 수
    max = 0;
    for(int i = 1; i <= num_of_buildings; i++) {
        
        // 시작점이 되는 빌딩의 입장에서 보이는 빌딩의 수
        int num_of_visible_building = get_visible_building(i);
        max = (num_of_visible_building > max) ? num_of_visible_building : max;
    }
    
    cout << max;
}

void MainClass::init_building_infos() {
    cin >> num_of_buildings;
    
    height.resize(num_of_buildings + 1);
    for(int i = 1; i <= num_of_buildings; i++) { cin >> height[i]; }
}

int MainClass::get_visible_building(int building_num) {
    int searching_building = building_num;      // 시작점에 해당되는 빌딩
    int target_building;                        // 종점에 해당되는 빌딩
    int cnt = 0;
    
    for(target_building = 1; target_building <= num_of_buildings; target_building++) {
        // 시작점 빌딩에서 종점 빌딩이 보이는지 여부
        bool able_to_see_target_building = true;
        
        if(target_building == searching_building) { continue; }
        
        // 시작점과 종점을 잇는 선분을 쉽게 구하기 위해 좌측 점과 우측 점을 구한다.
        int sp = min(searching_building, target_building);
        int ep = max(searching_building, target_building);
        
        // 시작점과 종점을 잇는 선분의 기울기값과 상수값을 구한다.
        auto [inc, con] = get_inc_and_cons({sp, height[sp]}, {ep, height[ep]});
        
        // 시작점 빌딩과 종점 빌딩 사이 모든 빌딩들에 각 빌딩들의 높이 값이 선분보다 위에 있는지 확인
        for(double cur_building = sp + 1; cur_building < ep; cur_building++) {
            double limit = inc * cur_building + con;
            if(limit <= height[cur_building]) { able_to_see_target_building = false; break; }
        }
        
        // 선분 위에 있는 점이 없으면 cnt++
        if(able_to_see_target_building) { cnt++; }
    }
    
    return cnt;
}

pair<double, double>MainClass::get_inc_and_cons(pair<int, int> p1, pair<int, int> p2) {
    double inc = ((double)p2.y - p1.y) / ((double)p2.x - p1.x);
    double con = (double)p1.y - inc*p1.x;
    
    return {inc, con};
}
