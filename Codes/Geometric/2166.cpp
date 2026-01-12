#include <iostream>
#include <algorithm>
#include <limits>
#include <list>

#define ld long double

using namespace std;

class MainClass {
public:
    void run();
private:
    int x[10001];
    int y[10001];
    int number_of_vertics;
    
    double total_area = 0;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> number_of_vertics;
    for(int i = 0 ; i < number_of_vertics; i++) { cin >> x[i] >> y[i]; }
    x[number_of_vertics] = x[0];
    y[number_of_vertics] = y[0];
    
    for(int i = 0; i < number_of_vertics; i++) {
        total_area += (double)x[i]*y[i+1];
        total_area -= (double)x[i+1]*y[i];
    }
    total_area = abs(total_area) *(0.5);
    
    printf("%.1lf", total_area);
}
