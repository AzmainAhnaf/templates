// Problem Name: Counting Patterns
// Problem Link: https://cses.fi/problemset/task/2103/

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

// Time Complexity: O(|s|log|s|)
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
    return ret;
}


void solve(int tst){
    string s;
    cin >> s;
    int n = (int)s.size();
    vi ans = suffix_array(s);
    vi SA = vi(ans.begin() + 1, ans.end());
    int k;
    cin >> k;
    while(k--){
        string t;
        cin >> t;
        int m = (int)t.size();
        int l = -1, r = n;
        if (m > n) {
            cout << "0\n";
            continue;
        }

        while (l < r - 1){
            int mid = l + (r - l) / 2;
            if (s.substr(SA[mid], m) >= t) r = mid;
            else l = mid;
        }
        int ans = -r;
        l = -1, r = n;
        while (l < r - 1){
            int mid = l + (r - l) / 2;
            if (s.substr(SA[mid], m) > t) r = mid;
            else l = mid;
        }
        ans += r;
        cout << ans << "\n";
    }
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
