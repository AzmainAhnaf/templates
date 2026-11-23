// problem name: Sort Points by Argument
// Problem link: https://judge.yosupo.jp/problem/sort_points_by_argument

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #pragma GCC optimize("O3")
// #pragma GCC target("sse4")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi2,lzcnt")

#define vi vector<int>
#define PB push_back
#define MP make_pair
#define vll vector<long long>
#define ll long long
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define ld long double
#define vld vector<long double>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define pld pair<ld, ld>
#define vpii vector<pair<int, int>>
#define GCD __gcd
#define INT __int128

#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>


const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int inf = 1e9;
const ld eps = 1e-6;
const ll inv2 = (mod + 1) / 2ll;
const ld pi = acos(-1);

struct PT {

    ll x, y;

    PT() {
        x = 0, y = 0;
    }

    PT(ll _x, ll _y) {
        x = _x;
        y = _y;
    }

    PT operator+ (PT &other) {
        return {x + other.x, y + other.y};
    }

    PT operator- (PT &other) {
        return {x - other.x, y - other.y};
    }

    ld abs() {
        return sqrtl((ld)(x * x) + (ld)(y * y));
    }

};

ll sign(ll val) {
    return (val > 0) - (val < 0);
}

ll dot(PT a, PT b) {
    return a.x * b.x + a.y * b.y;
}

ll cross(PT a, PT b) {
    return a.x * b.y - b.x * a.y;
}

ll orient(PT a, PT b, PT c) {
    return sign(cross(b - a, c - a));
}

bool half(PT a) {
    return a.y > 0 || (a.y == 0 && a.x <= 0);
}

ll norm2(PT a) {
    return a.x * a.x + a.y * a.y;
}

ld angle(PT a, PT b) {
    ld costheta = dot(a, b) / (a.abs() * b.abs());
    costheta = max((ld)-1, min((ld)1, costheta));
    return acos(costheta);
}

void polar_sort(vector<PT> &a) {
    sort(all(a), [](PT a, PT b) {
        return make_tuple(half(a), 0, norm2(a)) < make_tuple(half(b), cross(a, b), norm2(b));
    });
}

void solve(int tst){
    
    int n;
    cin >> n;

    vector<PT> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;  

    polar_sort(a);

    for(int i = 0; i < n; i++) {
        cout << a[i].x << " " << a[i].y << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // pre();
    int tc = 1;
    // cin >> tc;
    // freopen("angle2.in", "r", stdin);
    // freopen("angle2.out", "w", stdout);
    for (int i = 1; i <= tc; i++) solve(i);
    return 0;
}
