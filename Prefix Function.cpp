// Problem Name: String Matching
// Problem Link: https://cses.fi/problemset/task/1753

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

vi prefix_function(string &s){
    int n = s.size();
    vi pi(n);
    for (int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

void solve(int tst){

    string s, t;
    cin >> s >> t;
    int n = t.size();
    int m = s.size();
    s = t + "#" + s;
    vi pi = prefix_function(s);
    int ans = 0;
    for (int i = 0; i <= n + m; i++){
        if (pi[i] == n) ans++;
    }
    cout << ans << "\n";
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
