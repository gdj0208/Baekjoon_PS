#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>

#define street 0
#define house 1
#define chicken_house 2

using namespace std;

class Alg {
private:
    int size_of_city;
    int available_chicken_house;
    int num_of_chicken_house;
    int **city;
    vector<pair<int, int>> house_list;
    vector<pair<int, int>> chicken_house_list;
    vector<vector<pair<int, int>>> check_list;
    
public:
    void run();
    
private:
    void init_graph();
    void combine(int start, int n, vector<pair<int,int>>& elements, vector<pair<int,int>>& combination, vector<vector<pair<int,int>>>& result);
    vector<vector<pair<int,int>>> combinations(vector<pair<int,int>>& elements, int n);
    void get_dist();
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    /*
     1. 그래프 초기화
     2. 치킨집 선택
     3. 선택한 치킨집들에 대하여 최소거리의 합을 구함
     4. 구한 최소거리를 최소값들로 갱신
     */
    init_graph();
    check_list = combinations(chicken_house_list, available_chicken_house);
    get_dist();
}

void Alg::init_graph() {
    num_of_chicken_house = 0;
    cin >> size_of_city >> available_chicken_house;
    
    city = new int*[size_of_city];
    for(int i = 0; i < size_of_city; i++) { city[i] = new int[size_of_city]; }
    
    
    for(int y = 0; y < size_of_city; y++) {
        for(int x = 0; x < size_of_city; x++) { 
            cin >> city[y][x];
            if(city[y][x] == house) { house_list.push_back({y,x}); }
            else if(city[y][x] == chicken_house) { chicken_house_list.push_back({y,x}); }
        }
    }
}

void Alg::combine(int start, int n, vector<pair<int,int>>& elements, vector<pair<int,int>>& combination, vector<vector<pair<int,int>>>& result) {
    if (combination.size() == n) {
        result.push_back(combination);
        return;
    }

    for (int i = start; i < elements.size(); ++i) {
        combination.push_back(elements[i]);
        combine(i + 1, n, elements, combination, result);
        combination.pop_back();
    }
}

vector<vector<pair<int,int>>> Alg::combinations(vector<pair<int,int>>& elements, int n) {
    vector<vector<pair<int,int>>> result;
    vector<pair<int,int>> combination;
    combine(0, n, elements, combination, result);
    return result;
}
void Alg::get_dist() {
    int min_dist = 1e8;
    int total_dist;
    int tmp_dist;
    int *dist;
    dist = new int[house_list.size()];
    
    for(auto list : check_list) {
        total_dist = 0;
        fill(dist, dist + house_list.size(), 1e8);
        
        for(int i = 0; i < house_list.size(); i++) {
            for(auto c_house : list) {
                tmp_dist = abs(house_list[i].first - c_house.first) + abs(house_list[i].second - c_house.second);
                dist[i] = (tmp_dist < dist[i]) ? tmp_dist : dist[i];
            }
            
            total_dist += dist[i];
        }
        
        min_dist = (total_dist < min_dist) ? total_dist : min_dist;
    }
    
    cout << min_dist;
}
