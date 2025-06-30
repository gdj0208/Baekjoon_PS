#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>

#define INF 0x3f3f3f3f

using namespace std;

class Alg {
private:
    vector<pair<int, int>> adj[20005];
    int num_of_ver, num_of_edge;
    int start_ver;
    int *dist;
    
public:
    void run();
    
private:
    void init_graph();
    void get_dist();
    void print_ans();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    init_graph();
    get_dist();
    print_ans();
    //cout << "check";
}

void Alg::init_graph() {
    int s, e, w;
    
    cin >> num_of_ver >> num_of_edge;
    cin >> start_ver;
    
    for(int i = 0; i < num_of_edge; i++) {
        cin >> s >> e >> w;
        adj[s].push_back({e, w});
    }
}

void Alg::get_dist() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >check_list;
    int check, cur_dist;
    
    dist = new int[num_of_ver + 1];
    fill(dist, dist + num_of_ver + 1, INF);
    
    dist[start_ver] = 0;
    check_list.push(make_pair(0, start_ver));
    
    while(!check_list.empty()) {
        cur_dist = check_list.top().first;
        check = check_list.top().second;
        check_list.pop();
        
        if(cur_dist != dist[check]) { continue; }
        
        for(auto edge : adj[check])  {
            int next = edge.first;
            int weight = edge.second;
            
            if(cur_dist + weight < dist[next]) {
                dist[next] = cur_dist + weight;
                check_list.push(make_pair(dist[next], next));
            }
        }
    }
}

void Alg::print_ans() {
    for(int i = 1; i <= num_of_ver; i++) {
        if(dist[i] == INF) { cout << "INF\n"; }
        else { cout << dist[i] << "\n"; }
    }
}
