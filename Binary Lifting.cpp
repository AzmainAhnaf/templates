// Problem: given a tree rooted at node 0, find
// the k-th ancestor of node i in logarithmic time

#include <bits/stdc++.h>

using namespace std;

// Macros
#define REP(i, j, n) for(int i = j; i < n; i++)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define F first
#define S second

// Type Names
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

int LG = 16; // should be log(n) + 1 where n = number of nodes
vector<vi> parent, adj;
vi dep;
// parent[i][j] = 2^j-th ancestor of the node i

// preprocessing
void dfs(int node, int par){
    for (int next: adj[node]){
        if (next != par){
            dep[next] = dep[node] + 1;
            parent[next][0] = node;
            for (int j = 1; j <= LG; j++){
                parent[next][j] = parent[parent[next][j - 1]][j - 1];
            }
            dfs(next, node);
        }
    }
}

int main(){
    int n, u, v;
    cin >> n;
    parent.assign(n, vector<int>(LG + 1));
    adj.assign(n, vector<int>());
    dep.assign(n, 0);
    REP(i, 0, n - 1){
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    dfs(0, -1);
    int q;
    cin >> q;
    while(q--){
        int i, k;
        cin >> i >> k;
        // returning -1 if less than k ancestor present
        if (dep[i] < k){
            cout << "-1\n";
            continue;
        }
        for (int j = 0; j <= LG; j++){
            if (k & (1 << j)) i = parent[i][j];
        }
        cout << i << "\n";
    }
}
