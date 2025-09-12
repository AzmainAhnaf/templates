// Problem Name: Unionfind
// Problem Link: https://judge.yosupo.jp/problem/unionfind

#include <bits/stdc++.h>
 
using namespace std;
 
// Type Names
typedef long long ll;
typedef vector<int> vi;
 
// if there are n nodes 1 indexed then use DSU(n) in constructor
// if there are n nodes 0 indexed then using DSU(n - 1) is sufficient
struct DSU {

    vi p, size;

    DSU(int n){
        p.resize(n + 1);
        for (int i = 1; i <= n; i++) p[i] = i;
        size.assign(n + 1, 1);
    }

    int get(int a){
        if (a != p[a]){
            p[a] = get(p[a]);
        }
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);
        if (a != b){
            if (size[a] < size[b]) swap(a, b);
            p[b] = a;
            size[a] += size[b];
        }
    }

};

void solve(int tc){
    int n, q;
    cin >> n >> q;

    // as nodes are 0-indexed
    DSU dsu(n - 1);

    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if (!t){
            dsu.merge(u, v);
        }
        else {
            cout << (dsu.get(u) == dsu.get(v)) << "\n";
        }
    }
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // srand(time(NULL));
    // pre();
    // freopen("inputf.in", "r", stdin);
    // freopen("outputf..out", "w", stdout);
    int i = 1;
    // int t = 1;
    // cin >> t;
    // for(i = 1; i <= t; i++)
    solve(i);
    return 0;
}