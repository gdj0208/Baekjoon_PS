#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>

#define ll long long
#define hole 0

using namespace std;

class MainClass {
public:
    void run();
    
private:
    vector<pair<int, int>> jew;
    vector<int> bag;
    int jew_num, bag_num;
    
    void init_data();
    ll get_sum_value();
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    init_data();
    cout << get_sum_value();
}

void MainClass::init_data() {
    int weight, value;
    
    cin >> jew_num >> bag_num;
    
    for(int i = 0; i < jew_num; i++) {
        cin >> weight >> value;
        jew.push_back({weight, value});
    }
    
    for(int i = 0; i < bag_num; i++) {
        cin >> weight;
        bag.push_back(weight);
    }
}

ll MainClass::get_sum_value() {
    priority_queue<int, vector<int>, less<int>> pq;
    int idx = 0;
    ll value_sum = 0;
    
    
    sort(jew.begin(), jew.end());   // 보석을 가치 순으로 정렬
    sort(bag.begin(), bag.end());   // 가방을 수용량 순으로 정렬
    
    for(int i = 0; i < bag_num; i++) {
        
        // 각 보석별로 가방 수용량보다 가벼운 보석들에 대하여 가장 가치 높은 것들을 넣음.
        while(idx < jew_num and bag[i] >= jew[idx].first) {
            pq.push(jew[idx].second);
            idx++;
        }
        
        // pq에는 무게순으로 정렬된 각 가방별로 넣을 수 있는 가장 높은 가치의 보석이 들어가있다.
        if(!pq.empty()) {
            value_sum += pq.top();
            pq.pop();
        }
    }
    
    return value_sum;
}

