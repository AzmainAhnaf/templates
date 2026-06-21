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

void solve(int tst){   

    ll ans = INF;

    ll a, n;
    cin >> a >> n;

    vll d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    if (a == 0){
        cout << d[0] << "\n";
        return;
    }

    {
        for (int j = 0; j < n; j++){
            ll check = 0;
            for (int i = 0; i < 18; i++){
                check = (check * 10ll) + d[j];
                ans = min(ans, abs(a - check));
            }
        }
    }

    if (n >= 2) {
        ll check = d[1];
        ans = min(ans, abs(a - check));
        for (int i = 0; i < 17; i++){
            check = (check * 10ll) + d[0];
            ans = min(ans, abs(a - check));
        }
    }

    string s = to_string(a);
    int sz = s.size();

    // boro;
    for (int mark = -1; mark < sz; mark++){
        string check = "";
        bool flag = false;
        for (int i = 0; i < sz; i++){
            if (flag) {
                check += ('0' + d[0]);
                continue;
            }
            for (int j = 0; j < n; j++){
                if ((s[i] - '0') == d[j] && i != mark){
                    check += ('0' + d[j]);
                    break;
                }
                else if ((s[i] - '0') < d[j]){
                    check += ('0' + d[j]);
                    flag = true;
                    break;
                }
            }
        }
        if ((int)check.size()) ans = min(ans, abs(a - stoll(check)));
    }


    // choto
    for (int mark = -1; mark < sz; mark++){
        bool flag = false;
        string check = "";
        for (int i = 0; i < sz; i++){
            if (flag) {
                check += ('0' + d[n - 1]);
                continue;
            }
            for (int j = n - 1; j >= 0; j--){
                if ((s[i] - '0') == d[j] && i != mark){
                    check += ('0' + d[j]);
                    break;
                }
                else if ((s[i] - '0') > d[j]) {
                    check += ('0' + d[j]);
                    flag = true;
                    break;
                }
            }
        }

        if ((int)check.size()) ans = min(ans, abs(a - stoll(check)));

    }

    cout << ans << "\n";

}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // pre();
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++){
        solve(i);
    }
    return 0;
}