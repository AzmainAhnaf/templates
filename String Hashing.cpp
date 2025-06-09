// Solution to CSES: String Matching
// Problem Link: https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>

using namespace std;

// Type Names
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

const int mxn = 1e6;
ll pw1[mxn + 3];
ll pw2[mxn + 3];
const ll m1 = 1e9 + 1011;
const ll m2 = 1e9 + 1011;
ll b1 = 1e9 + 21, b2 = 1e9 + 181;

void pre() {
    pw1[0]=pw2[0]=1;

    for(int i=1;i<mxn;i++)
    {
        pw1[i]=(pw1[i-1]*b1)%m1;
        pw2[i]=(pw2[i-1]*b2)%m2;

    }
}

struct Hash {
    vector<ll> h1, h2;
    void init(string s) {
        int n = s.size();
        h1.resize(n + 2);
        h2.resize(n + 2);
        h1[0] = s[0] * pw1[0] % m1;
        h2[0] = s[0] * pw2[0] % m2;
        for (int i = 1; i < n; i++) {
            h1[i] = ((h1[i-1] * b1) % m1 + s[i]) % m1;
            h2[i] = ((h2[i-1] * b2) % m2 + s[i]) % m2;
        }

    }
    ll hashval(int l,int r) {
        if(l == 0) {
            ll a = (h1[r] + m1) % m1;
            ll b = (h2[r] + m2) % m2;
            return a << 32 | b;
        }
        ll x = (h1[r] - (h1[l - 1] * pw1[r - l + 1]) % m1 + m1) % m1;
        ll y = (h2[r] - (h2[l - 1] * pw2[r - l + 1]) % m2 + m2) % m2;
        return x << 32 | y;
    }
};

void solve(int tc) {
    string s, t;
    cin >> s >> t;
    Hash h1, h2;
    h1.init(s);
    h2.init(t);
    ll check = h2.hashval(0, t.size() - 1);
    ll ct = 0;
    for (int i = 0; i + t.size() - 1 < s.size(); i++){
        if (check == h1.hashval(i, i + t.size() - 1)) ct++;
    }
    cout << ct << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    pre();
    // freopen("inputf.in", "r", stdin);
    // freopen("outputf..out", "w", stdout);
    int i = 1;
    // int t = 1;
    // cin >> t;
    // for(i = 1; i <= t; i++)
    solve(i);
    return 0;
}