//
//  main.cpp
//  ProblemSolving
//
//  Created by 구동준 on 12/24/24.
//

#include <iostream>
#include <list>
#include <set>

using namespace std;

class PS {
public:
    void run();
    
private:
    set<int> *ver;
    int *parent;
    int num_ver;
    int num_edge;
    int num_adopter;
    
    void init_graph();
    int find_closest_parent();
};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    PS* solver = new PS();
    solver->run();
    
    return 0;
}


void PS::run() {
    int rpt;
    
    cin >> rpt;
    
    while(rpt--) {
        init_graph();
        cout << find_closest_parent() << "\n";
    }
}

void PS::init_graph() {
    int sp, ep;
    
    cin >> num_ver;
    num_edge = num_ver - 1;
    
    ver = new set<int>[num_ver + 1];
    parent = new int[num_ver + 1];
    
    for(int i = 0; i < num_ver; i++) { parent[i] = i; }
    
    for(int i = 0; i < num_edge; i++) {
        cin >> sp >> ep;
        ver[sp].insert(ep);
        parent[ep] = sp;
    }
}

int PS::find_closest_parent() {
    set<int> ancester;
    int p1, p2;
    int closest_parent = -1;
    
    cin >> p1 >> p2;
    
    while(true) {
        ancester.insert(p1);
        ancester.insert(p2);
        
        p1 = parent[p1];
        p2 = parent[p2];
        
        if(p1 != parent[p1] and ancester.find(p1) != ancester.end()) { return p1; }
        if(p2 != parent[p2] and ancester.find(p2) != ancester.end()) { return p2; }
        
        if(p1 == p2) { return p1; }
    }
    
    return closest_parent;
}
