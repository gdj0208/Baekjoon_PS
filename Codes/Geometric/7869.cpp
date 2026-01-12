#include <iostream>
#include <algorithm>
#include <limits>
#include <math.h>

#define ld long double

using namespace std;

class MainClass {
public:
    void run();
private:
    double x1, y1, x2, y2, r1, r2;
    double d;
    double area;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    d = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    
    if(d >= r1 + r2) { area = 0; }
    else if(d <= abs(r1-r2)) { area = M_PI * pow(min(r1, r2), 2); }
    else {
        double angle1 = acos((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
        double angle2 = acos((d * d + r2 * r2 - r1 * r1) / (2 * d * r2));

        double area1 = r1 * r1 * angle1;
        double area2 = r2 * r2 * angle2;

        double area3 = 0.5 * sqrt((-d + r1 + r2) * (d + r1 - r2) * (d - r1 + r2) * (d + r1 + r2));
        
        area = area1 + area2 - area3;
    }
    printf("%.03lf", round(area * 1000) / 1000);
}

