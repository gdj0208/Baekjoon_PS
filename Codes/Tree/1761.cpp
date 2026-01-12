#include <iostream>
#include <algorithm>
#include <cstring>
#include <list>

#define ll long long
#define INF 1e8

using namespace std;

class MainClass {
public:
    void run();
    
private:
    vector<unordered_map<int, int>> ver;
    vector<int>dst, level, parent;
    int head = 0;
    int ver_num = 0;
    int rpt = 0;
    
    void init_graph();
    int find_head();
    void complete_tree();
    void get_dist();
    int get_anc(int v1, int v2);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init_graph();
    head = find_head();
    complete_tree();
    
    cin >> rpt;
    while(rpt--) { get_dist(); }
}

void MainClass::init_graph() {
    int v1, v2, weight;
    
    cin >> ver_num;
    
    ver.resize(ver_num + 1);
    
    for(int i = 0; i < ver_num - 1; i++) {
        cin >> v1 >> v2 >> weight;
        
        ver[v1].insert({v2, weight});
        ver[v2].insert({v1, weight});
    }
}

int MainClass::find_head() {
    for(int i = 1; i <= ver_num; i++) {
        if(ver[i].size() == 1) { return ver_num; }
    }
    return -1;
}

void MainClass::complete_tree() {
    list<int>queue;
    int ver_idx;
    
    queue.push_back(head);
    
    dst.resize(ver_num + 1, -1);
    level.resize(ver_num + 1, 0);
    parent.resize(ver_num + 1, 0);
    
    dst[head] = 0;
    level[head] = 0;
    parent[head] = head;
    
    while(!queue.empty()) {
        ver_idx = queue.front();
        queue.pop_front();
        
        for(auto i : ver[ver_idx]) {
            if(dst[i.first] == -1) {
                dst[i.first] = dst[ver_idx] + i.second;
                level[i.first] = level[ver_idx] + 1;
                parent[i.first] = ver_idx;
                
                queue.push_back(i.first);
            }
        }
    }
}

void MainClass::get_dist() {
    int v1, v2, anc;
    cin >> v1 >> v2;
    
    anc = get_anc(v1, v2);
    cout << dst[v1] + dst[v2] - 2*dst[anc] << "\n";
}

int MainClass::get_anc(int v1, int v2) {
    int low = (level[v1] < level[v2]) ? v2 : v1;
    int high = (level[v1] < level[v2]) ? v1 : v2;
    
    while(level[low] != level[high]) { low = parent[low]; }
    while(low != high) { low = parent[low]; high = parent[high]; }
    
    return low;
}
