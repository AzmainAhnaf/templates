// Problem Name: Convux Hull
// Problem Link: https://cses.fi/problemset/task/2195

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
// Macros
#define REP(i, j, n) for(int i = j; i < n; i++)
#define trav(i, a) for(auto i: a)
#define all(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define F first
#define S second
#define GCD __gcd
#define DEBUG(i) cout << "DEBUG " << i << "\n";
#define CASE(i) cout << "Case " << i << ": ";
#define MEM(arr, val) memset(arr, val, sizeof(arr));
 
// Type Names
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef long double ld;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
tree_order_statistics_node_update> ordered_multiset;
 
// functions    
template <typename T>
void pv(vector<T> &a){
    for (auto elem: a){
        cout << elem << " ";
    }
    cout << "\n";
}

// Global Variables
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll INF = 1e18;

struct pt {
    ll x, y;

    // empty constructor
    pt(){
        x = 0, y = 0;
    }

    // parameterized constructor
    pt (ll a, ll b){
        x = a, y = b;
    }
};

ll cross(pt a, pt b, pt c){
    // return negative for clockwise turn
    // return positive for counter clockwise turn
    return ((b.x - a.x) * (c.y - a.y)) - ((c.x - a.x) * (b.y - a.y));
}

bool cw(pt a, pt b, pt c, bool include_collinear){
    ll o = cross(a, b, c);
    return (o < 0) || (include_collinear && o == 0);
}

bool ccw(pt a, pt b, pt c, bool include_collinear){
    ll o = cross(a, b, c);
    return (o > 0) || (include_collinear && o == 0);
}

bool cmp(pt a, pt b){
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}

struct ConvexHull {

    vector<pt> a;
    vector<pt> hull;
    bool include_collinear;

    ConvexHull(vector<pt> &b, bool flag){
        a = b;
        include_collinear = flag;
        sort(all(a), cmp);
    }

    void build(){
        if (a.size() == 1) {
            hull = a;
            return;
        }
        pt p1 = a[0], p2 = a.back();
        vector<pt> up, down;
        up.PB(p1);
        down.PB(p1);
        int n = a.size();
        for (int i = 1; i < n; i++){
            if (i == n - 1 || cw(p1, a[i], p2, include_collinear)){
                int sz = up.size();
                while (sz >= 2 && !cw(up[sz - 2], up[sz - 1], a[i], include_collinear)){
                    up.pop_back();
                    sz--;
                }
                up.push_back(a[i]);
                sz++;
            }
            if (i == n - 1 || ccw(p1, a[i], p2, include_collinear)){
                int sz = down.size();
                while (sz >= 2 && !ccw(down[sz - 2], down[sz - 1], a[i], include_collinear)){
                    down.pop_back();
                    sz--;
                }
                down.push_back(a[i]);
                sz++;
            }
        }
        if (include_collinear && up.size() == a.size()){
            hull = a;
            reverse(all(hull));
            return;
        }
        for (int i = 0; i < (int)up.size(); i++){
            hull.PB(up[i]);
        }
        for (int i = (int)down.size() - 2; i > 0; i--){
            hull.PB(down[i]);
        }
    }
};

void solve(int tc){

    int n;
    cin >> n;
    vector<pt> a(n);

    REP(i, 0, n) cin >> a[i].x >> a[i].y;
    sort(all(a), cmp);

    ConvexHull ch(a, true);
    ch.build();

    cout << ch.hull.size() << "\n";

    for (int i = 0; i < (int)ch.hull.size(); i++){
        cout << ch.hull[i].x << " " << ch.hull[i].y << "\n";
    }
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // pre();
    // freopen("inputf.in", "r", stdin);
    // freopen("outputf..out", "w", stdout);
    int i = 1;
    // int t = 1;
    // cin >> t;
    // for(i = 1; i <= t; i++)
    solve(i);
    return 0;
}