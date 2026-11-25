// Problem Name: Apples and Bananas
// Problem Link: https://cses.fi/problemset/task/2111/

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

struct base {

    double a, b;
    base(double a = 0, double b = 0) : a(a), b(b) {}
    const base operator + (const base &c) const {
        return base(a + c.a, b + c.b);
    }
    const base operator - (const base &c) const {
        return base(a - c.a, b - c.b);
    }
    const base operator * (const base &c) const {
        return base(a * c.a - b * c.b, a * c.b + b * c.a);
    }
};

void fft(vector<base> &p, bool inv = 0) {
    int n = (int)p.size(), i = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(p[i], p[j]);
    }
    for (int l = 1, m; (m = l << 1) <= n; l <<= 1) {
        double ang = 2 * pi / m;
        base wn = base(cos(ang), (inv ? 1. : -1.) * sin(ang)), w;
        for (int i = 0, j, k; i < n; i += m) {
            for (w = base(1, 0), j = i, k = i + l; j < k; j++, w = w * wn) {
                base t = w * p[j + l];
                p[j + l] = p[j] - t;
                p[j] = p[j] + t;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) {
            p[i].a /= n;
            p[i].b /= n;
        }
    }
}

vll multiply (vi &a, vi &b) {
    int n = (int)a.size(), m = (int)b.size(), t = n + m - 1, sz = 1;
    while (sz < t) sz <<= 1;
    vector<base> x(sz), y(sz), z(sz);
    for (int i = 0; i < sz; i++) {
        x[i] = i < (int)a.size() ? base(a[i], 0) : base(0, 0);
        y[i] = i < (int)b.size() ? base(b[i], 0) : base(0, 0);
    }
    fft(x), fft(y);
    for (int i = 0; i < sz; i++) z[i] = x[i] * y[i];
    fft(z, 1);
    vll ret(sz);
    for (int i = 0; i < sz; i++) ret[i] = (ll) round(z[i].a);
    while ((int)ret.size() > 1 && ret.back() == 0) ret.pop_back();
    return ret;
}

void solve(int tst){

    int k, n, m;
    cin >> k >> n >> m;

    vi a(k + 1), b(k + 1);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b[x]++;
    }

    vll res = multiply(a, b);

    for (int i = 2; i <= 2 * k; i++) {
        if (i >= (int)res.size()) cout << "0 ";
        else cout << res[i] << " ";
    }
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // pre();
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++) solve(i);
    return 0;
}
