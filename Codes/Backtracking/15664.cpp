#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>

#define INF 1e7
using namespace std;

class Alg {
private:
    int size_of_list, print_size;
    vector<int> com;
    vector<int> num_list;
    bool *visit;
    
public:
    void run();
    
private:
    void sort_vector();
    void get_num_list();
    void print_num(int num);
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    cin >> size_of_list >> print_size;
    
    visit = new bool[size_of_list];
    fill(visit, visit + size_of_list, false);
    
    get_num_list();
    sort_vector();
    
    print_num(1);
}

void Alg::get_num_list() {
    int tmp;
    for(int i = 0; i < size_of_list; i++) {
        cin >> tmp;
        num_list.push_back(tmp);
    }
}

void Alg::sort_vector() {
    int n = num_list.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (num_list[j] > num_list[j + 1]) {
                    swap(num_list[j], num_list[j + 1]);
                }
            }
        }
}

void Alg::print_num(int num) {
    int prev = 0;
    
    if(com.size() == print_size) {
        for(auto i : com) { cout << num_list[i] << " "; }
        cout << "\n";
        return;
    }
    
    for(int i = num - 1; i < size_of_list; i++) {
        if(visit[i] == true) { continue; }
        if(num_list[i] == prev) { continue; }
        
        visit[i] = true;
        com.push_back(i);
        prev = num_list[i];
        
        print_num(i + 1);
        
        visit[i] = false;
        com.pop_back();
    }
}
