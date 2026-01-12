#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <list>
#include <utility>

#define ll long long
#define x first
#define y second

using namespace std;

class Alg {
private:
    vector<pair<ll, ll>> point;
    
public:
    void run();
    
private:
    void init_graph();
    ll get_ccw(pair<ll, ll>, pair<ll, ll>, pair<ll, ll>);
    bool is_overlapping();
    bool is_between(pair<ll, ll>, pair<ll, ll>, pair<ll, ll>);
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
     1. 그래프를 초기화 합니다.
     2. 두 선분이 교차하는지 확인합니다. (Counter Clock Wise 알고리즘을 사용합니다.)
        
        < Counter Clock Wise(CCW) 알고리즘은 다음과 같습니다. >
        1. CCW알고리즘은 점a,b,c가 있을 때 a->b->c로 선을 그었을 때 그 선이 어느 방향으로 도는지를 파악하는 알고리즘입니다.
        2. 다음은 파악하는 방법입니다.
            * 벡터 a->b를 구합니다.
            * 벡터 b->c를 구합니다.
            * 벡터 a->b와 벡터 b->c의 외적을 구합니다.
            * 외적 값이 양수가 나올 시 시계방향으로 도는 것이며, 음수일 경우 반시계방향, 0일 경우 직선입니다.
              ( 오른손 법칙 )
     
        < 다음은 두 선분이 교차하는지를 확인하는 조건입니다. >
        1. 두 선분이 교차하는지를 확인힙니다.
            * 어느 한 선분A의 양 끝점 a1, a2가 있습니다.
            * 다른 선분B의 양 끝점 b1, b2가 있습니다.
            * (a1, a2, b1)에 대해 CCW 값을 구하고, (a1, a2, b2)에 대해서도 CCW값을 구합니다.
            * 두 결과값을 곲했을 때 음수가 나온다면 하나는 양수, 다른 하나는 음수임으로 두 선분을 무한히 연장할 시 겹친다는 것을 알 수 있습니다.
        2. 두 선분이 겹치는지를 확인합니다.
            * 두 선분이 겹칠 시 CCW의 값은 0입니다.
            * 또한 한 선분의 끝점 중 하나가 다른 선분의 양 끝점 사이에 있어야 합니다.
     */
    
    init_graph();
    
    if(is_overlapping()) { cout << 1;}
    else { cout << 0; }
}

void Alg::init_graph() {
    int x1, x2, y1, y2;
    
    cin >> x1 >> y1 >> x2 >> y2;
    point.push_back(make_pair(x1, y1));
    point.push_back(make_pair(x2, y2));
    
    cin >> x1 >> y1 >> x2 >> y2;
    point.push_back(make_pair(x1, y1));
    point.push_back(make_pair(x2, y2));
}

ll Alg::get_ccw(pair<ll, ll> v1, pair<ll, ll> v2, pair<ll, ll> v3) {
    // 아래는 벡터v1->v2와 벡터v2->v3의 외적 공식입니다.
    ll ans = (v2.x - v1.x) * (v3.y - v1.y) - (v2.y - v1.y) * (v3.x - v1.x);
    if(ans < 0) { return -1; }
    else if(ans > 0) { return 1; }
    else { return 0; }
}

bool Alg::is_between(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    // 아래는 c가 a와 b 사이에 있는지 확인하는 코드입니다.
    if (min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
        min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y)) {
        return true;
    }
    return false;
}

bool Alg::is_overlapping() {
    ll ccw1 = get_ccw(point[0], point[1], point[2]);
    ll ccw2 = get_ccw(point[0], point[1], point[3]);
    ll ccw3 = get_ccw(point[2], point[3], point[0]);
    ll ccw4 = get_ccw(point[2], point[3], point[1]);
    
    // 두 선분이 교차하는 경우
    if (ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) { return true; }
    
    // 선분이 일직선 상에 있는 경우
    if (ccw1 == 0 && is_between(point[0], point[1], point[2])) return true;
    if (ccw2 == 0 && is_between(point[0], point[1], point[3])) return true;
    if (ccw3 == 0 && is_between(point[2], point[3], point[0])) return true;
    if (ccw4 == 0 && is_between(point[2], point[3], point[1])) return true;
    
    return false;
}
