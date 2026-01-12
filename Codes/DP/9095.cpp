#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

#define ll long long

using namespace std;

class MainClass {
public:
    void run();
private:
    int num, rpt;
    int count[11];
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> rpt;
    while(rpt--) {
        cin >> num;
        count[1] = 1;
        count[2] = 2;
        count[3] = 4;
        
        for(int i = 4; i <= num; i++) { count[i] = count[i-3] + count[i-2] + count[i-1]; }
        
        cout << count[num] << "\n";
    }
    
}
