// Problem Name: Distinct Substrings
// Problem Link: https://cses.fi/problemset/task/2105

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int inf = 1e9;

vector<int> sort_cyclic_shifts(string const &s){
    int n = s.size();
    const int alphabet = 256;
    vi p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++){
        cnt[s[i]]++;
    }
    for (int i = 1; i < alphabet; i++){
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++){
        p[--cnt[s[i]]] = i;
    }
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++){
        if (s[p[i]] != s[p[i - 1]]){
            classes++;
        }
        c[p[i]] = classes - 1;
    }
    vi pn(n), cn(n);
    for (int h = 0; (1 << h) < n; h++){
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; i++){
            cnt[c[pn[i]]]++;
        }
        for (int i = 1; i < classes; i++){
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--){
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++){
            pii cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pii prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev){
                classes++;
            }
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array(string s){
    s += '$';
    vi ret = sort_cyclic_shifts(s);
    ret = vi(ret.begin() + 1, ret.end());
    return ret;
}

// Kasai's Algo
// p = suffix array
// lcp[i] = length of lcp starting at index p[i] and p[i + 1]
vi lcp_construction(string const &s, vi const &p){
    int n = s.size();
    vi rank(n, 0);
    for (int i = 0; i < n; i++){
        rank[p[i]] = i;
    }

    int k = 0;
    vi lcp(n - 1, 0);
    for (int i = 0; i < n; i++){
        if (rank[i] == n - 1){
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]){
            k++;
        }
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}

void solve(int tst){
    string s;
    cin >> s;

    vi p = suffix_array(s);

    vi lcp = lcp_construction(s, p);

    ll n = s.size();

    ll ans = (n * (n + 1)) / 2ll;
    for (auto elem: lcp) ans -= elem;
    cout << ans << "\n";

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