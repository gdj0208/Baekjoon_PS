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
    ll ans = (v2.x - v1.x) * (v3.y - v1.y) - (v2.y - v1.y) * (v3.x - v1.x);
    if(ans < 0) { return -1; }
    else if(ans > 0) { return 1; }
    else { return 0; }
}

bool Alg::is_between(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    // c가 a와 b 사이에 있는지 확인
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
