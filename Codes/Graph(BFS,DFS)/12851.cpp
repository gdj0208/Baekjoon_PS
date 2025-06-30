#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <utility>

#define INF 1e8
#define limit 100001

using namespace std;

class Alg {
private:
    int dp[limit] = {0};
    int cnt[limit] = {0};
    int start, end;
    
public:
    void run();
    
private:
    void init_data();
    void get_dist();
    bool is_out_of_bound(int num);
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Alg* alg = new Alg;
    alg->run();
}

void Alg::run() {
    
    cin >> start >> end;
    get_dist();
    cout << dp[end] << "\n" << cnt[end];
}

void Alg::get_dist() {
    list<pair<int, int>> check_list, tmp_list;
    int check_cnt, check_loc, next;
    bool reached_end = false;
    
    fill(dp, dp + limit, INF);
    fill(cnt, cnt + limit, 0);
    tmp_list.push_back({1, start});
    dp[start] = 0;
    cnt[start] = 1;
    
    while(!tmp_list.empty() and !reached_end) {
        check_list = tmp_list;
        tmp_list.clear();
        
        while(!check_list.empty()) {
            check_cnt = check_list.front().first;
            check_loc = check_list.front().second;
            check_list.pop_front();
            
            for(int i = 0; i < 3; i++) {
                switch (i) {
                    case 0:     next = check_loc - 1;   break;
                    case 1:     next = check_loc + 1;   break;
                    default :   next = 2 * check_loc;   break;
                }
                
                if(is_out_of_bound(next)) { continue; }
                if(next == end) { reached_end = true; }
                
                //cnt[next] += cnt[check_loc];
                //cnt[next]++;
                if(dp[next] == INF) {
                    dp[next] = dp[check_loc] + 1;
                    cnt[next] = cnt[check_loc];
                    tmp_list.push_back({cnt[next], next});
                }
                else if(dp[next] == dp[check_loc] + 1) {
                    cnt[next] += cnt[check_loc];
                }
            }
        }
    }
}

bool Alg::is_out_of_bound(int num) { return num < 0 or limit < num; }
