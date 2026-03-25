// Problem Name: GCD Table
// Problem Link: https://codeforces.com/problemset/problem/338/D

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #pragma GCCoptimize("O3")
// #pragma GCCtarget("sse4")
// #pragma GCCoptimize("unroll-loops")

#define vi vector<int>
#define PB push_back
#define vll vector<long long>
#define ll long long
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define ld long double
#define vld vector<long double>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define GCD __gcd
#define INT __int128

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int inf = 1e9;

// ax + by = __gcd(a, b)
// returns __gcd(a, b)
INT extended_euclid(INT a, INT b, INT &x, INT &y){
    INT xx = y = 0;
    INT yy = x = 1;
    while (b){
        INT q = a / b;
        INT t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}

// finds x such that x % m1 = a1, x % m2 = a2. m1 and m2 may not be coprime
// here, x is unique module m = lcm(m1, m2). returns (x, m). on failure, m = -1
pair<INT, INT> CRT(INT a1, INT m1, INT a2, INT m2){
    INT p, q;
    INT g = extended_euclid(m1, m2, p, q);
    if (a1 % g != a2 % g) return make_pair(-1, -1);
    INT m = m1 / g * m2;
    p = (p % m + m) % m;
    q = (q % m + m) % m;
    return make_pair((p * a2 % m * (m1 / g) % m + q * a1 % m * (m2 / g) % m) % m, m);
}

// intersecting AP of two APs: (a1 + d1x) and (a2 + d2x)
pll intersect(ll a1, ll d1, ll a2, ll d2){
    auto x = CRT(a1 % d1, d1, a2 % d2, d2);
    ll a = x.F, d = x.S;
    if (d == -1) return {0, 0}; // empty and non-intersecting
    ll st = max(a1, a2);
    a = a < st ? a + (((st - a + d - 1) / d) * d) : a; // while (a < st) a += d;
    return {a, d}; // (a + dx) intersecting AP
}

void solve(int tst){

    ll n, m, k;
    cin >> n >> m >> k;

    vll a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    ll LCM = 1;
    for (int i = 0; i < k; i++){
        LCM = (a[i] * LCM) / (__gcd(LCM, a[i]));
        if (LCM > n){
            cout << "NO\n";
            return;
        }
    }

    vector<pll> cong(k);

    for (int i = 0; i < k; i++){
        cong[i] = {(((-i) % a[i]) + a[i]) % a[i], a[i]};
    }

    for (int i = 0; i + 1 < k; i++){
        cong[i + 1] = CRT(cong[i].F, cong[i].S, cong[i + 1].F, cong[i + 1].S);
        ll j = cong[i + 1].F;
        if (j + k - 1 > m || j == -1){
            cout << "NO\n";
            return;
        }
    }

    pll j = cong[k - 1];
    if (j.F == 0) j.F += j.S;

    if (j.F + k - 1 > m || j.F == -1) {
        cout << "NO\n";
        return;
    }

    vll b(k);

    for (ll i = 0; i < k; i++){
        b[i] = __gcd(LCM, j.F + i);
    }

    if (a == b) cout << "YES\n";
    else cout << "NO\n";

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // pre();
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++){
        solve(i);
    }
    return 0;
}
