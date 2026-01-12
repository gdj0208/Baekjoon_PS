#include <iostream>
#include <algorithm>
#include <limits>
#include <list>
#include <unordered_set>
#include <math.h>


using namespace std;

class MainClass {
public:
    void run();
    
private:
    vector<int> root;               // 각 도시들의 최종 루트
    int number_of_city;
    int number_of_city_to_visit;
    
    void init_info();
    void check_all_same_root();
    void change_all_root(int from, int to);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    /*
     풀이방법
     1. 각 도시들의 최종 루트를 자신으로 선택합니다.
     2. 도시들간 연결 정보를 입력받습니다.
        -> 입력받은 도시 중 번호가 더 큰 도시a와 번호가 더 작은 도시b가 있습니다.
        -> 도시a와 같은 루트를 같는 모든 도시들에 대해서 도시b의 루트 값을 갖게 합니다.
     3. 최종 비교시 비교하는 모든 도시들이 같은 루트 값을 보유하면 YES를 아니면 NO를 출력합니다.
     */
    
    cin >> number_of_city >> number_of_city_to_visit;
    init_info();
    check_all_same_root();
}

void MainClass::init_info() {
    bool is_connected;
    
    root.resize(number_of_city + 1);
    for(int i = 1; i <= number_of_city; i++) { root[i] = i; }
    
    // 도시간 연결 정보를 입력
    for(int city_num = 1; city_num <= number_of_city; city_num++) {
        for(int next_city = 1; next_city <= number_of_city; next_city++) {
            cin >> is_connected;
            
            // 연결된 도시일 경우
            if(is_connected) {
                
                // 입력받은 도시 중 번호가 더 큰 도시a와 번호가 더 작은 도시b가 있습니다.
                // 도시a와 같은 루트를 같는 모든 도시들에 대해서 도시b의 루트 값을 갖게 합니다.
                if(root[city_num] < root[next_city]) { change_all_root(root[next_city], root[city_num]); }
                else { change_all_root(root[city_num], root[next_city]); }
            }
        }
    }
}

void MainClass::change_all_root(int from, int to) {
    for(int i = 1; i <= number_of_city; i++) { root[i] = (root[i] == from) ? to : root[i]; }
}

void MainClass::check_all_same_root() {
    int city_num, tmp_root;
    int final_root;
    
    cin >> city_num;
    final_root = root[city_num];
    
    for(int i = 1; i < number_of_city_to_visit; i++) {
        cin >> city_num;
        
        tmp_root = root[city_num];
        if(final_root != tmp_root) { cout << "NO"; return; }
    }
    cout << "YES";
}

