// Solution to: CSES: Bit Problem
// Problem Link: https://cses.fi/problemset/task/1654/
// time complexity: O(N * 2^N)
// space complexity: O(N * 2^N)

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
#define CASE(i) cout << "Case " << i << ":";
#define MEM(arr, val) memset(arr, val, sizeof(arr));

// Type Names
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;


// Global Variables
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll INF = 1e18;

const int N = 20;
// dp[number of lsb allowed to change][mask]
// sub to calculate sum of all submask
// sup to calculate sum of all supermask
long long dp_sub[N + 1][(1 << N) + 5], dp_sup[N + 1][(1 << N) + 5];

void solve(ll tc){
    memset(dp_sub, 0ll, sizeof(dp_sub));
    memset(dp_sup, 0ll, sizeof(dp_sup));
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        dp_sub[0][a[i]] += 1;
        dp_sup[0][a[i]] += 1;
    }

    // calculating dp_sub
    for (int p = 1; p <= N; p++){
        for (int mask = 0; mask < (1 << N); mask++){
            if (mask & (1 << (p - 1))){
                dp_sub[p][mask] = dp_sub[p - 1][mask] + dp_sub[p - 1][mask ^ (1 << (p - 1))];
            }
            else {
                dp_sub[p][mask] = dp_sub[p - 1][mask];
            }
        }
    }

    // calculating dp_sup
    for (int p = 1; p <= N; p++){
        for (int mask = (1 << N) - 1; mask >= 0; mask--){
            if ((~mask) & (1 << (p - 1))){
                dp_sup[p][mask] = dp_sup[p - 1][mask] + dp_sup[p - 1][mask ^ (1 << (p - 1))];
            }
            else {
                dp_sup[p][mask] = dp_sup[p - 1][mask];
            }
        }
    }

    // calculating ans;
    for (int i = 0; i < n; i++){
        int c = ~a[i];
        c = c & ((1 << 20) - 1);
        cout << dp_sub[N][a[i]] << " " << dp_sup[N][a[i]] << " " << n - dp_sub[N][c] << "\n";
    }

}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("inputf..in", "r", stdin);
    // freopen("outputf..out", "w", stdout);
    int i = 1;
    // int t = 1;
    // cin >> t;
    // for(i = 1; i <= t; i++)
    solve(i);
    return 0;
}
