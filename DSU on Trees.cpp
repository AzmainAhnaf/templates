// Problem Name: Distinct Colors
// Problem Link: https://cses.fi/problemset/task/1139/

#include <bits/stdc++.h>
 
using namespace std;
 
// Macros
#define REP(i, j, n) for(int i = j; i < n; i++)
#define PB push_back
 
// Type Names
typedef vector<int> vi;
typedef vector<long long> vll;

 
const int N = 200001;
int col[N], sz[N];
vector<int> adj[N];
unordered_map<int, int> freq;
int ans[N];
int ct = 0;

// initial DFS to get subtree size
int getsz(int node, int par){
    int size = 1;
    for (int next: adj[node]){
        if (next != par){
            size += getsz(next, node);
        }
    }
    return sz[node] = size;
}

// adding or removing info of a subtree
void add(int node, int par, int bigchild, int x){
    freq[col[node]] += x;
    if (freq[col[node]] == 1 && x == 1) ct++;
    else if (freq[col[node]] == 0 && x == -1) ct--;
    for (int next: adj[node]){
        if (next != par && next != bigchild) add(next, node, -1, x);
    }
}

// main dfs, keep = 1 for bigchild for not removing subtree info
void dfs(int node, int par, int keep){
    int bigchild = -1, mx = -1;
    for (int next: adj[node]){
        if (next != par && sz[next] > mx){
            bigchild = next;
            mx = sz[next];
        }
    }
    for (int next: adj[node]){
        if (next != par && next != bigchild){
            dfs(next, node, 0);
        }
    }
    if (bigchild != -1){
        dfs(bigchild, node, 1);
    }
    add(node, par, bigchild, 1);
    ans[node] = ct;
    if (keep == 0){
        add(node, par, -1, -1);
    }
}

void solve(){
    int n;
    cin >> n;
    REP(i, 1, n + 1) cin >> col[i];
    REP(i, 1, n){
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    getsz(1, 1);
    dfs(1, 1, 1);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}