#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <algorithm>

#define ll long long

using namespace std;

class Alg {
private:
    vector<pair<int, int>> pairs;
    static bool Compare(const pair<int,int>& a, const pair<int, int>& b);
    
public:
    void run();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    int size_of_pairs;
    int n1, n2;
    
    cin >> size_of_pairs;
    pairs.resize(size_of_pairs);
    
    for(int i = 0; i < size_of_pairs; i++) {
        cin >> n1 >> n2;
        pairs[i] = {n1, n2};
    }
    
    sort(pairs.begin(), pairs.end(), Compare);
    
    for(auto p : pairs) {  cout << p.first << " " << p.second << "\n"; }
}

bool Alg::Compare(const pair<int,int>& a, const pair<int, int>& b) {
    if(a.second == b.second) { return a.first < b.first; }
    return a.second < b.second;
}
