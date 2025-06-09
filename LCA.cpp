// solution to Problem: Lowest Common Ancestor
// Link: https://www.spoj.com/problems/LCASQ/

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

int LG = 14; // should be log(n) + 1 where n = number of nodes
vector<vi> parent, children;
vi dep;
// parent[i][j] = 2^j-th ancestor of the node i

// preprocessing
void dfs(int node, int par){
    for (int next: children[node]){
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

int get_lca(int a, int b){
    if (dep[a] < dep[b]) swap(a, b);
    int k = dep[a] - dep[b];
    for (int j = LG; j >= 0; j--){
        if (k & (1 << j)) a = parent[a][j];
    }
    if (a == b) return a;

    for (int j = LG; j >= 0; j--){
        if (parent[a][j] != parent[b][j]){
            a = parent[a][j];
            b = parent[b][j];
        }
    }

    return parent[a][0];

}

int main(){
    int n;
    cin >> n;
    parent.assign(n, vi(LG + 1));
    children.assign(n, vi());
    dep.assign(n, 0);
    REP(i, 0, n){
        int m;
        cin >> m;
        while(m--){
            int u;
            cin >> u;
            children[i].PB(u);
        }
    }
    dfs(0, -1);
    int q;
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        cout << get_lca(a, b) << "\n";
    }
    return 0;
}
