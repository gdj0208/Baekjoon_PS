#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>

#define INF 1e9

using namespace std;

class Alg {
public:
    void run();
private:
    int rpt;
    int num_of_com, num_of_net;
    int hacking_com;
    int time[10001];
    vector<unordered_map<int, int>> Net;
    
    void init_graph();
    void hacking_start();
    void get_num_of_hacked_com_and_time();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    cin >> rpt;
    while(rpt--) {
        init_graph();
        hacking_start();
        get_num_of_hacked_com_and_time();
    }
}

void Alg::init_graph() {
    int s, e, w;
    
    cin >> num_of_com >> num_of_net >> hacking_com;
    Net.clear();
    Net.resize(num_of_com + 1);
    
    for(int i = 0; i < num_of_net; i++) {
        cin >> s >> e >> w;
        Net[e][s] = w;
    }
}

void Alg::hacking_start() {
    int cur_com, cur_t;
    fill(time, time + num_of_com + 1, INF);
    
    list<pair<int, int>> check_list;
    check_list.push_back({hacking_com, 0});
    time[hacking_com] = 0;
    
    while(!check_list.empty()) {
        cur_com = check_list.front().first;
        cur_t = check_list.front().second;
        check_list.pop_front();
        
        for(auto attack : Net[cur_com]) {
            int next_com = attack.first;
            int next_t = cur_t + attack.second;
            
            if(time[next_com] > next_t) {
                time[next_com] = next_t;
                check_list.push_back({next_com, time[next_com]});
            }
        }
    }
}

void Alg::get_num_of_hacked_com_and_time() {
    int max_time = 0;
    int num_of_hacked_com = 0;
    
    for(int i = 1; i <= num_of_com; i++) {
        if(time[i] == INF) { continue; }
        
        num_of_hacked_com++;
        max_time = (time[i] > max_time) ? time[i] : max_time;
    }
    
    cout << num_of_hacked_com << " " << max_time << "\n";
}
