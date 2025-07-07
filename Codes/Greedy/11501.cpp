#include <iostream>
#include <algorithm>
#include <math.h>
#include <list>

using namespace std;

class MainClass {
public:
    void run();
private:
    int rpt, day;
    int list_num;
    long long revenue;
    int arr[1000001];
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    
    int max;
    
    cin >> rpt;
    while(rpt--) {
        
        revenue = 0;
        
        // 1. 숫자들 입력
        cin >> day;
        for(int d = 0; d < day; d++) { cin >> arr[d]; }
        
        max = arr[day - 1];
        for(int d = day - 2; d >= 0; d--) {
            if(max < arr[d]) { max = arr[d]; }
            revenue += max - arr[d];
        }
        
        cout << revenue << "\n";
    }
}
