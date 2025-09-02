 
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
#define CASE(i) cout << "Case " << i << ": ";
#define MEM(arr, val) memset(arr, val, sizeof(arr));
 
// Type Names
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef long double ld;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
tree_order_statistics_node_update> ordered_multiset;
 
// functions
template <typename T>
void pv(vector<T> &a){
    for (auto elem: a){
        cout << elem << " ";
    }
    cout << "\n";
}

// Global Variables
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll INF = 1e18;

vector<bool> visited;
vi tin, low;
vector<vi> adj;
int timer;
map<pair<int, int>, bool> bridge;
vi color;
vi dist;


void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridge[{min(to, v), max(to, v)}] = true;
        }
    }
}

void dfs2(int cur, int col){
    visited[cur] = true;
    color[cur] = col;
    for (int next: adj[cur]){
        if (!visited[next]) dfs2(next, col);
    }
}

bool odd = false;

void bfs(int start){
    queue<int> order;
    order.push(start);
    dist[start] = 0;
    while (!order.empty()){
        int cur = order.front();
        order.pop();
        for (int next: adj[cur]){
            if (dist[next] > dist[cur] + 1){
                dist[next] = dist[cur] + 1;
                order.push(next);
            }
            else {
                if ((dist[cur] - dist[next]) % 2 == 0) odd = true;
            }
        }
    }
}

void solve(int tc){

    ll n, m, k;
    cin >> n >> m >> k;

    bridge.clear();
    adj.assign(n + 1, vi());
    visited.assign(n + 1, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    color.assign(n + 1, 0);
    dist.assign(n + 1, n + 10);
    timer = 0;

    vector<pair<int, int>> edge;

    vi a(n + 1);
    REP(i, 1, n + 1) cin >> a[i];

    REP(i, 0, m){
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
        edge.PB({min(u, v), max(u, v)});
    }

    dfs(1);

    adj.assign(n + 1, vi());
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++){
        int u, v;
        tie(u, v) = edge[i];
        if (!bridge[{u, v}]){
            adj[u].PB(v);
            adj[v].PB(u);
        }
    }

    int T = 0;

    for (int i = 1; i <= n; i++){
        if (!visited[i]) dfs2(i, ++T);
    }

    vector<vi> dol(T + 1);

    ll ans = 1;

    for (int i = 1; i <= n; i++){
        dol[color[i]].PB(i);
    }

    for (int i = 1; i <= T; i++){
        odd = false;
        int sordar = dol[i][0];
        if ((int)dol[i].size() == 1) {
            if (a[sordar] == -1){
                ans *= k;
                ans %= mod;
            }
            continue;
        }
        bfs(sordar);
        ll gun = k;
        if (odd) {
            gun = 1;
            for (int sangopango: dol[i]){
                if (a[sangopango] > 0) {
                    gun = 0;
                    break;
                }
            }
        }
        else {
            int val = -1;
            for (int sangopango: dol[i]) {
                if (val != -1 && a[sangopango] != val && a[sangopango] != -1) {
                    gun = 0;
                    break;
                }
                if (a[sangopango] > -1){
                    val = a[sangopango];
                    gun = 1;
                }
            }
        }
        ans *= gun;
        ans %= mod;
    }

    // for (auto pr: bridge){
    //     if (pr.S) cout << pr.F.F << " " << pr.F.S << "\n";
    // }

    cout << ans << "\n";


}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // pre();
    // freopen("inputf.in", "r", stdin);
    // freopen("outputf..out", "w", stdout);
    int i = 1;
    int t = 1;
    cin >> t;
    for(i = 1; i <= t; i++)
    solve(i);
    return 0;
}