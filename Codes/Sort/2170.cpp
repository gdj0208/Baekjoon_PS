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
    int number_of_line;
    int total_length;
    vector<pair<int, int>> Lines;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int s, e;
    int prev_s, prev_e;
    
    cin >> number_of_line;
    for(int i = 0; i < number_of_line; i++) {
        cin >> s >> e;
        Lines.push_back(make_pair(s, e));
    }
    
    sort(Lines.begin(), Lines.end());
    
    total_length = 0;
    prev_s = prev_e = numeric_limits<int>::min();
    
    for(auto line : Lines) {
        //cout << line.first << " " << line.second << "\n";
        
        s = line.first;
        e = line.second;
        
        if(prev_s <= s and e <= prev_e) { continue; }
        else if(prev_e <= s) {
            total_length += (e - s);
            prev_e = e;
            prev_s = s;
        }
        else if(prev_s < s and prev_e < e) {
            total_length += (e - prev_e);
            prev_s = s;
            prev_e = e;
        }
    }
    
    cout << total_length;
}
