#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>

using namespace std;

class MainClass {
public:
    void run();
private:
    list<pair<int, int>> classes;
    int rpt;
    
    void init();
    void get_classes_in_need();
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init();
    get_classes_in_need();
}

void MainClass::init() {
    int s, e;
    
    cin >> rpt;
    
    while(rpt--) {
        cin >> s >> e;
        classes.push_back(make_pair(e, s));
        
    }
    
    classes.sort();
    
    //for(auto i : classes) { cout << i.first << " " << i.second << "\n"; }
}

void MainClass::get_classes_in_need() {
    int t, need;
    
    t = need = 0;
    
    for(auto i = classes.begin(); i != classes.end(); i++) {
        if((*i).second >= t) {
            need++;
            t = (*i).first;
        }
    }
    
    cout << need;
}
