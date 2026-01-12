#include <iostream>
#include <algorithm>
#include <limits>
#include <list>
#include <math.h>

#define x first
#define y second

using namespace std;

class MainClass {
public:
    void run();
    
private:
    pair<double, double> cur_loc;
    double dist;
    double jump_dist, jump_time, jump_speed;
    
    double walking_all_way() { return dist; }
    double jump_n_times_and_walk();
    double jump_n_times_and_go_back();
    double jump_n_times() { return (dist / jump_dist + 1)*jump_time; }
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    double cnt = 0;
    double min = 1e9;
    
    cin >> cur_loc.x >> cur_loc.y >> jump_dist >> jump_time;
    
    dist = sqrt(cur_loc.x*cur_loc.x + cur_loc.y*cur_loc.y);
    jump_speed = jump_dist/jump_time;
    
    for(int i = 0; i < 4; i++) {
        switch (i) {
            case 0: //  전부 걸어가는 경우
                cnt = walking_all_way();
                break;
            case 1: // n번 점프하고 남은 거리 걸어가기
                cnt = jump_n_times_and_walk();
                break;
            case 2: // n+1번 점프하고 지나온 거리 돌아가기
                cnt = jump_n_times_and_go_back();
                break;
            case 3: // n+1번 점프하기
                cnt = (dist <= 2*jump_dist) ? 2*jump_time : ((int)(dist/jump_dist) + 1)*jump_time;
                break;
        }
        
        // 최소값 탐색
        min = (min < cnt) ? min : cnt;
    }
    printf("%.9lf", min);
}

double MainClass::jump_n_times_and_walk() {
    int jump_cnt = dist / jump_dist;
    double dist_left = dist - jump_dist * jump_cnt;
    double total_time = jump_cnt * jump_time + dist_left;
    
    return total_time;
}

double MainClass::jump_n_times_and_go_back() {
    int jump_cnt = dist / jump_dist + 1;
    double dist_left = dist - jump_dist * jump_cnt;
    double total_time = jump_cnt * jump_time + abs(dist_left);
    
    return total_time;
}

