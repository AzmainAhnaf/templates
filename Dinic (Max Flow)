// Problem Name: Download Speed
// Problem Link: https://vjudge.net/problem/CSES-1694

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

struct FlowEdge {
    int v, u;
    int cap, flow = 0;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const int flow_inf = 1e9;
    vector<FlowEdge> edges;
    vector<vi> adj;
    int n, m = 0;
    int s, t;
    vi level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n + 1);
        level.resize(n + 1);
        ptr.resize(n + 1);
    }

    void add_edge(int v, int u, ll cap){
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0ll);
        adj[v].PB(m);
        adj[u].PB(m + 1);
        m += 2;
    }

    bool bfs(){
        while (!q.empty()){
            int v = q.front();
            q.pop();
            for (int id: adj[v]){
                if (edges[id].cap == edges[id].flow) continue;
                if (level[edges[id].u] != -1) continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    int dfs(int v, int pushed) {
        if (pushed == 0)
            return 0;
        if (v == t){
            return pushed;
        }
        for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++){
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u]) continue;
            int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow(){
        ll f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, flow_inf)){
                f += pushed;
            }
        }
        return f;
    }

};


void solve(int tst){   

    int n, m;
    cin >> n >> m;

    Dinic dinic(n, 1, n);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        dinic.add_edge(u, v, w);
    }

    cout << dinic.flow() << "\n";
    

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
