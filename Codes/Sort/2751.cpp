#include <iostream>
#include <algorithm>
#include <limits>
#include <list>


using namespace std;

class MainClass {
public:
    void run();
    
private:
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int size_of_v, tmp;
    vector<int> v;
    
    cin >> size_of_v;
    
    for(int i = 0; i < size_of_v; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    for(auto i : v) { cout << i << "\n"; }
}
