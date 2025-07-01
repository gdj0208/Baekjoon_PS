#include <iostream>
#include <list>
#include <algorithm>
#include <math.h>
#include <time.h>

#define ll long long

using namespace std;

class MainClass {
public:
    void run();
private:
    int rpt;
    ll max, room;
    list<int> start, end;
    
    void add_room();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    int s,e;
    
    max = room = 0;
    cin >> rpt;
    
    while (rpt--) {
        cin >> s >> e;
        start.push_back(s);
        end.push_back(e);
    }
    
    start.sort();
    end.sort();
    
    while(!start.empty()) {
        if(start.front() < end.front()) {
            room++;
            start.pop_front();
        }
        else if(start.front() > end.front()) {
            room--;
            end.pop_front();
        }
        else {
            start.pop_front();
            end.pop_front();
        }
        
        max = (room > max) ? room : max;
    }
    
    cout << max;
}
