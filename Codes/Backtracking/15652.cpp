#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>

#define INF 1e7
using namespace std;

class Alg {
private:
    int m, n;
    vector<int> com;
    
public:
    void run();
    
private:
    void print_num(int num);
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    cin >> m >> n;
    print_num(1);
}

void Alg::print_num(int num) {
    if(com.size() == n) { 
        for(auto i : com) { cout << i << " "; }
        cout << "\n";
        return;
    }
    
    for(int i = num; i <= m; i++) {
        com.push_back(i);
        print_num(i);
        com.pop_back();
    }
}
