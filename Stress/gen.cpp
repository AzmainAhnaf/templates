// stress test to following problem
// link: https://codeforces.com/contest/2228/problem/C2

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r) (rng);
}


void solve(int tst){    
    cout << "1\n";
    int n = rand(1, 10);
    cout << rand(0, (ll)1e17) << " " << n << "\n";
    int last = 0;
    for (int i = 0; i < n; i++) {
        int cur = rand(last, 9 - (n - i - 1));
        cout << cur << " ";
        last = cur + 1;
    }
    cout << "\n";

}

int main(){
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
