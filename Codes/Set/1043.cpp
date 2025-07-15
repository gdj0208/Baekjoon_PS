#include <iostream>
#include <algorithm>
#include <limits>
#include <list>
#include <unordered_map>
#include <unordered_set>

#define null NULL

using namespace std;

class MainClass {
public:
    void run();
private:
    class Vertic{
    public:
        Vertic(int n) { num = n; }
        bool visitied = false;
        int num;
        unordered_set<Vertic*> adj;
    };
    int number_of_people, number_of_party;
    int number_of_people_in_party, people_who_knows;
    int tmp;
    int cnt;
    
    unordered_map<int, Vertic*> Vertics;
    list<Vertic*> who_knows;
    list<list<Vertic*>*> partys;
    
    void run_bfs();
    bool nobody_knows(list<Vertic*>*);
};

int main() {
    MainClass mainClass;
    mainClass.run();
}

void MainClass::run() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cnt = 0;
    
    // 사람 정보 초기화
    cin >> number_of_people >> number_of_party;
    for(int i = 1; i <= number_of_people; i++) { Vertics[i] = new Vertic(i); }
    
    // 아는 사람 목록 초기화
    cin >> people_who_knows;
    for(int i = 1; i <= people_who_knows; i++) { cin >> tmp; who_knows.push_back(Vertics[tmp]); }
    
    // 각 파티를 입력받으면서 그래프 생성
    for(int i = 0; i < number_of_party; i++) {
        list<Vertic*>* party = new list<Vertic*>;
        
        // 파티 인원수 입력 받고 파티 형성
        cin >> number_of_people_in_party;
        for(int j = 0; j < number_of_people_in_party; j++) { cin >> tmp; party->push_back(Vertics[tmp]); }
        
        // 파티 인원들에 대해 관계그래프 형성
        for(auto p1 : *party) {
            for(auto p2 : *party) {
                if(p1 != p2) {
                    p1->adj.insert(p2);
                    p2->adj.insert(p1);
                }
            }
        }
        
        partys.push_back(party);
    }
    
    //bfs 돌리기
    run_bfs();
    
    // 모든 파티원들이 bfs때 방문하지 않았을 시 카운트 +1
    for(auto p : partys) { if(nobody_knows(p)) { cnt++; } }
    
    cout << cnt;
}

void MainClass::run_bfs() {
    list<Vertic*> check_list, tmp_list;
    Vertic* check;
    
    tmp_list = who_knows;
    
    while(!tmp_list.empty()) {
        check_list = tmp_list;
        tmp_list.clear();
        
        while(!check_list.empty()) {
            check = check_list.front();
            check_list.pop_front();
            
            if(check->visitied == false) {
                check->visitied = true;
                for(auto v : check->adj) {
                    if(v->visitied == false) { tmp_list.push_back(v); }
                }
            }
        }
    }
}

bool MainClass::nobody_knows(list<Vertic *> *a_party) {
    for(auto people : *a_party) { if(people->visitied == true) { return false; } }
    return true;
}
