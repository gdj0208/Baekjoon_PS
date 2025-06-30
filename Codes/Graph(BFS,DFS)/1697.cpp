#include <iostream>
#include <algorithm>
#include <limits>
#include <list>

#define null NULL
#define start -1
#define end -2
#define limit 100001

using namespace std;

class MainClass {
public:
    void run();
private:
    int arr[limit] = {0};
    int s, e, cnt, loc;
    bool reached;
    list<int> check_list, tmp_list;
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cnt = 1;
    reached = false;
    
    cin >> s >> e;
    
    tmp_list.push_back(s);
    
    while(!tmp_list.empty() and reached == false) {
        check_list = tmp_list;
        tmp_list.clear();
        
        while(!check_list.empty() and reached == false) {
            loc = check_list.front();
            check_list.pop_front();
            
            if(loc == e) { reached = true; break; }
            
            if(0 <= loc - 1) { if(arr[loc-1] > cnt or arr[loc-1] <= 0) { arr[loc-1] = cnt; tmp_list.push_back(loc-1); } }
            if(loc + 1 < limit) { if(arr[loc+1] > cnt or arr[loc+1] <= 0) { arr[loc+1] = cnt; tmp_list.push_back(loc+1); } }
            if(2*loc < limit) { if(arr[2*loc] > cnt or arr[2*loc] <= 0) { arr[2*loc] = cnt; tmp_list.push_back(2*loc); } }
        }
        
        cnt++;
    }
    
    cout << arr[e];
}

