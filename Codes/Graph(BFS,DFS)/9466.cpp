#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

class Alg {
private:
    int rpt, size;
    int select[100001];
    bool visit[100001];
    bool in_group[100001];
    int num_of_team = 0;
    
public:
    void run();
    
private:
    void init_graph();
    void dfs(int node);
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
        
        fill(visit, visit + 100001, false);
        fill(in_group, in_group + 100001, false);
        num_of_team = 0;
        
        for(int i = 1; i <= size; i++) {
            if(!in_group[i]) { dfs(i); }
        }
        
        cout << size - num_of_team << "\n";
    }
}

void Alg::init_graph() {
    cin >> size;
    
    fill(in_group, in_group + size + 1, false);
    
    select[0] = 0;
    for(int i = 1; i <= size; i++) { cin >> select[i]; }
    
}

void Alg::dfs(int node) {
    visit[node] = true;
    int next = select[node];
    
    if (!visit[next]) {
        dfs(next);
    } else if (!in_group[next]) {
        for (int i = next; i != node; i = select[i]) {
            num_of_team++;
        }
        num_of_team++;
    }
    
    in_group[node] = true;
}
