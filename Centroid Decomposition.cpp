// Solution to Problem: D. Distance in Tree
// Problem Link: https://codeforces.com/problemset/problem/161/D

#include <bits/stdc++.h>

using namespace std;

// macros
#define PB push_back

// Type Names
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

// Global Variables
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll INF = 1e18;
const int mxn = 50005;

vector<int> adj[mxn];
int sub[mxn] = {}, iscentroid[mxn] = {};
int cnt[mxn] = {};
ll ans = 0;
int k;

int dfs(int node, int par){
    sub[node] = 1;
    for (int next: adj[node]){
        if (par != next && !iscentroid[next]) sub[node] += dfs(next, node);
    }
    return sub[node];
}

int get_centroid(int node, int par, int n){
    for (int next: adj[node]){
        if (next != par && !iscentroid[next] && sub[next] > (n / 2)) return get_centroid(next, node, n);
    }
    return node;
}

void dfs2(int node, int par, int dep, int parity){
    if (parity == 1) cnt[dep]++;
    else if (parity == 0) cnt[dep]--;
    else {
        if (k - dep > 0) ans += cnt[k - dep];
        if (k == dep) ans += 2;
    }
    for (int next: adj[node]){
        if (next != par && !iscentroid[next]){
            dfs2(next, node, dep + 1, parity);
        }
    }
}

void decompose(int node, int par){
    int n = dfs(node, par);
    int centroid = get_centroid(node, par, n);
    for (int next: adj[centroid]){
        if (!iscentroid[next]){
            dfs2(next, centroid, 1, 1);
        }
    }
    for (int next: adj[centroid]){
        if (!iscentroid[next]){
            dfs2(next, centroid, 1, 0);
            dfs2(next, centroid, 1, 2);
            dfs2(next, centroid, 1, 1);
        }
    }
    for (int next: adj[centroid]){
        if (!iscentroid[next]){
            dfs2(next, centroid, 1, 0);
        }
    }
    iscentroid[centroid] = 1;
    for (int next: adj[centroid]){
        if (next != par && !iscentroid[next]) decompose(next, centroid);
    }   
}



void solve(ll tc){   
    int n, u, v;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++){
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    decompose(1, -1);
    cout << ans / 2 << "\n";
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("inputf.in", "r", stdin);
    // freopen("outputf..out", "w", stdout);
    int i = 1;
    // int t = 1;
    // cin >> t;
    // for(i = 1; i <= t; i++)
    solve(i);
    return 0;
}