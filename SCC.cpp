// problem name: Strongly Connected Components
// problem link: https://judge.yosupo.jp/problem/scc

#include <bits/stdc++.h>

using namespace std;

// #pragma GCC optimize("O3")
// #pragma GCC target("sse4")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi2,lzcnt")

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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int inf = 1e9;
const ld eps = 1e-4;

// adj -> graph
// adj_t -> transpose graph
// order -> topological order of condensation grpah after dfs3
// vis -> to maintain visited node
// id[u] -> u is part of which scc
// scc[u] -> which are the nodes that are part of scc labeled u
// adj_cond -> condensation graph
vector<vi> adj, adj_t;
vi order;
vi vis, id;
vector<vi> scc, adj_cond;

// first topsort to determine the order of calling dfs on adj_t
void dfs1(int node) {
    vis[node] = true;
    for (int next: adj[node]) {
        if (!vis[next]) dfs1(next);
    }
    order.PB(node);
}

// second dfs to determine the id of scc of each node
void dfs2(int node, int code) {
    vis[node] = true;
    id[node] = code;
    for (int next: adj_t[node]) {
        if (!vis[next]) dfs2(next, code);
    }
}

// third dfs for topological order of condensation graph
void dfs3(int node) {
    vis[node] = true;
    for (int next: adj_cond[node]) {
        if (!vis[next]) dfs3(next);
    }
    order.PB(node);
}

void solve(int tst){

    int n, m;
    cin >> n >> m;
    adj.assign(n, vi());
    adj_t.assign(n, vi());
    vis.assign(n, 0);
    id.assign(n, -1);

    vector<pii> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj_t[v].PB(u);
        edges.PB({u, v});
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs1(i);
    }

    reverse(all(order));
    int comp = 0; // scc count

    vis.assign(n, false);

    for (auto i: order) {
        if (!vis[i]) dfs2(i, comp++);
    }

    adj_cond.assign(comp, vi());
    vis.assign(comp, false);
    scc.assign(comp, vi());

    for (int i = 0; i < n; i++) {
        scc[id[i]].PB(i);
    }

    order.clear();

    for (auto elem: edges) {
        adj_cond[id[elem.F]].PB(id[elem.S]);
    }

    for (int i = 0; i < comp; i++) {
        if (!vis[i]) dfs3(i);
    }

    reverse(all(order));
    cout << comp << "\n";
    for (auto elem: order) {
        cout << (int)scc[elem].size() << " ";
        for (auto lm: scc[elem]) cout << lm << " ";
        cout << "\n";
    }

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