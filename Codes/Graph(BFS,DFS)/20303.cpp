#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <utility>


#define INF 1e9

using namespace std;

class Ver{
public:
    int weight;
    unordered_set<int> adj;
};

class Alg {
private:
    vector<pair<int, int>> Group;
    int num_of_ver, num_of_edge, limit;
    bool *visit;
    Ver *vertics;
    
public:
    void run();
    
private:
    void solve();
    void init_graph();
    void init_ver();
    void init_edge();
    bool* init_visit();
    void bfs(int s);
    void knapsack();
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
    solve();
}

void Alg::init_graph() {
    cin >> num_of_ver >> num_of_edge >> limit;
    
    init_ver();
    init_edge();
}

void Alg::init_ver() {
    vertics = new Ver[num_of_ver + 1];
    for(int i = 1; i <= num_of_ver; i++) { cin >> vertics[i].weight; }
}

void Alg::init_edge() {
    int v1, v2;
    for(int i = 0; i < num_of_edge; i++) {
        cin >> v1 >> v2;
        
        vertics[v1].adj.insert(v2);
        vertics[v2].adj.insert(v1);
    }
}

void Alg::solve() {
    int sum = 0;
    int people = 0;
    
    visit = init_visit();
    
    for(int i = 1; i <= num_of_ver; i++) {
        if(!visit[i]) { bfs(i); }
    }
    
    knapsack();
}

bool* Alg::init_visit() {
    bool* visit = new bool[num_of_ver + 1];
    fill(visit, visit + num_of_ver + 1, false);
    
    return visit;
}

void Alg::bfs(int s) {
    int sum = 0;
    int num_of_node = 0;
    
    
    queue<int> check_list;
    int check;
    
    check_list.push(s);
    visit[s] = true;
    
    sum += vertics[s].weight;
    num_of_node++;
    
    while(!check_list.empty()) {
        check = check_list.front();
        check_list.pop();
        
        for(auto a : vertics[check].adj) {
            if(visit[a]) { continue; }
            
            visit[a] = true;
            sum += vertics[a].weight;
            num_of_node++;
            
            check_list.push(a);
        }
    }
    
    Group.push_back(make_pair(sum, num_of_node));
}

void Alg::knapsack() {
    vector<int>dp (limit + 1, 0);
    
    for(auto g : Group) {
        int candy = g.first;
        int people = g.second;
        
        for(int j = limit; j > people; j--) { dp[j] = max(dp[j], dp[j - people] + candy); }
    }
    
    cout << dp[limit];
}
