#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class Alg {
public:
    void run();
    
private:
    string s1, s2;
    
    bool does_match(string str);
    string add_a(string str);
    string turn(string str);
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    cin >> s1 >> s2;
    
    while(true) {
        if(s2[s2.size()-1] == 'A') { s2.pop_back(); }
        else { s2.pop_back(); reverse(s2.begin(), s2.end()); }
        
        if(s1.size() == s2.size()) {
            if(s1 == s2) { cout << 1; }
            else { cout << 0;}
            
            return;
        }
    }
}