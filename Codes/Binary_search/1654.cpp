#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

class MainClass {
public:
    void run();
private:
    int line, line_in_need;
    int len_of_line[10000];
    
    void get_info();
    void get_len();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    
    get_info();
    get_len();
}

void MainClass::get_info() {
    cin >> line >> line_in_need;
    for(int i = 0; i < line; i++) { cin >> len_of_line[i]; }
}

void MainClass::get_len() {
    ll div_min, div_max, div_mid;
    ll lines_can_get;
    
    div_min = 1;
    div_max = 0x7fffffff;
    
    lines_can_get = 0;
    
    while(div_min < div_max) {
        div_mid = (div_min+div_max + 1) / 2;

        lines_can_get = 0;
        for(int i = 0; i < line; i++) { lines_can_get += len_of_line[i] / div_mid; }
        
        if(lines_can_get >= line_in_need) { div_min = div_mid; }
        else { div_max = div_mid - 1; }
    }
 
    cout << div_min;
}
