#include <iostream>
#include <list>
#define null NULL
#define MAX(a,b) a>b ? a:b
#define INF 1e9

using namespace std;

class Alg{
private:
    int num_of_roll, num_of_ledders, num_of_snakes;
    int board[101];
    int portal[101] = {0};
    
public:
    void run();
    
private:
    void init();
    int solve();
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(NULL);
    
    Alg alg;
    alg.run();
}


void Alg::run() {
    /*
     1. 각 칸별로 도달하는데 걸리는 횟수를 무한으로 초기화합니다.
     2. 1번 칸에서 시작하여 주사위를 굴렸을 때 나올 수 있는 모든 칸에 대해 주사위를 굴린 횟수가 기존 값보다 작으면 이를 저장합니다.
     */
    
    init();             // 보드판 관련 정보를 초기화합니다.
    cout << solve();
}

void Alg::init() {
    // 스네이크의 머리와 꼬리입니다.
    int v1, v2;
    
    // 다리의 수와 스네이크의 수를 저장합니다.
    cin >> num_of_ledders >> num_of_snakes;
    
    // 각 칸별로 도달하는데 걸리는 횟수를 무한으로 초기화합니다.
    fill(board, board + 100, INF);
    
    // 주사위를 굴린 횟수를 초기화합니다
    num_of_roll = 0;
    
    for(int i = 0; i < num_of_snakes + num_of_ledders; i++) {
        cin >> v1 >> v2;
        portal[v1] = v2;
    }
}

int Alg::solve() {
    int check_num, next_num;
    
    /*
     check_list는 이번에 주사위를 굴릴 때 시작점의 위치를 저장합니다.
     tmp_list는 다음에 주사위를 굴릴 때 시작점의 위치를 저장합니다.
     */
    list<int> check_list, tmp_list;
    
    tmp_list.push_back(1);
    board[1] = 0;
    
    // 다음에 주사위를 굴릴 시작점이 없을 시 자연스럽게 종료됩니다.
    while(!tmp_list.empty()) {
        
        // tmp_list의 시작점들을 check_list의 시작점 목록들로 옮기고 check_list의 목록들은 지웁니다.
        check_list = tmp_list;
        tmp_list.clear();
        
        // 주사위를 굴린 횟수를 1회 증가시킵니다.
        num_of_roll++;
        
        // 이번에 주사위를 굴릴 시작점이 없을 시 자연스럽게 종료됩니다.
        while(!check_list.empty()) {
            
            // check_num은 시작점입니다.
            check_num = check_list.front();
            check_list.pop_front();
            
            // 주사위를 굴려서 나오는 모든 칸에 대해 해당 칸 까지 오는데 걸린 횟수를 저장합니다.
            for(int i = 1; i <= 6; i++) {
                next_num = check_num + i;
                
                // 처음으로 마지막 칸에 도달할 시 더 조사할 필요 없이 주사위를 굴린 횟수를 반환합니다.
                if(next_num == 100) { return num_of_roll; }
                
                // 칸에 도달하는데 걸린 횟수를 저장합니다.
                if(num_of_roll < board[next_num]) {
                    board[next_num] = num_of_roll;
                    
                    if(portal[next_num] == 0) { tmp_list.push_back(next_num); }
                    else { tmp_list.push_back(portal[next_num]); }
                }
            }
        }
    }
    
    return board[100];
}
