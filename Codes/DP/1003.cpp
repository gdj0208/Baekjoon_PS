#include <iostream>
#include <list>
#include <queue>
#define null NULL
#define MAX(a,b) a>b ? a:b

using namespace std;

class Alg{
private:
    int rpt, num;
    int cnt_0[41];
    int cnt_1[41];
    
public:
    void run();
    void init_cnt();
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(NULL);
    
    Alg alg;
    alg.run();
}


void Alg::run() {
    
    cin >> rpt;
    init_cnt();
    while(rpt--) {
        cin >> num;
        cout << cnt_0[num] << " " << cnt_1[num] << "\n";
    }
    
}

void Alg::init_cnt() {
    cnt_0[0] = 1; cnt_0[1] = 0;
    cnt_1[0] = 0; cnt_1[1] = 1;
    
    for(int i = 2; i <= 40; i++) {
        cnt_0[i] = cnt_0[i - 1] + cnt_0[i - 2];
        cnt_1[i] = cnt_1[i - 1] + cnt_1[i - 2];
    }
}
