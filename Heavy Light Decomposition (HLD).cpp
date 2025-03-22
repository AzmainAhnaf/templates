// Solution to: LightOJ: Aladin and the Return Journey
// Problem Link: https://lightoj.com/problem/aladdin-and-the-return-journe

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
#define CASE(i) cout << "Case " << i << ":";
#define MEM(arr, val) memset(arr, val, sizeof(arr));

// Type Names
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;


// Global Variables
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll INF = 1e18;


// Note that HLD does not have to accompany with segment tree
// Other linear structure can also be integrated with graph using HLD
// Following HLD use segment tree
class HLD {
public:

    int n, size, curpos;
    vector<int> a, par, dep, heavy, head, pos;
    vector<long long> segtree;
    vector<vector<int>> adj;

    // a[u] -> Initial value of node u before any update
    // par[u] -> Immediate parrent of the node u. the parent of the root node is the root itself
    // dep[u] -> depth of the node u from the root
    // heavy[u] -> the child of the node u that belongs to the same heavy chain. -1 if leaf node
    // head[u] -> the head of the heavy chain the node u belongs to
    // pos[u] -> the node u resonate to which position in segtree
    // segree -> 0-indexed Segment tree
    // adj -> Adjacency list for graph traversal

    //initialization
    HLD(int n){
        this->n = n;
        curpos = 0;
        a.resize(n + 1);
        par.assign(n + 1, -1);
        dep.assign(n + 1, 0);
        heavy.assign(n + 1, -1);
        head.assign(n + 1, -1);
        pos.assign(n + 1, -1);
        size = 1;
        while (size < n) size *= 2;
        segtree.assign(2 * size, 0ll);
        adj.resize(n + 1);
    }

    // dfs that returns the size of the subtree of the node
    // the size helps us to determine the heavy array
    // this dfs calculate the heavy, dep and par array
    // u = current node, p = parent of the node
    int dfs(int  u, int p){
        int mx = 0, sz = 1;
        par[u] = p;
        for (int v: adj[u]){
            if (v == p) continue;
            dep[v] = dep[u] + 1;
            int subtree = dfs(v, u);
            sz += subtree;
            if (subtree > mx){
                mx = subtree;
                heavy[u] = v;
            }
        }
        return sz;
    }

    // segtree functionlity
    // update(i, v) -> update the value at index i to v
    void update(int i, int v, int x, int lx, int rx){
        if (rx - lx == 1){
            segtree[x] = v;
            return;
        }
        int m = (lx + rx) >> 1;
        if (i < m) update(i, v, 2 * x + 1, lx, m);
        else update(i, v, 2 * x + 2, m, rx);
        segtree[x] = segtree[2 * x + 1] + segtree[2 * x + 2];
    }

    void update(int i, int v){
        update(i, v, 0, 0, size);
    }

    // calc(l, r) -> calculate the sum of index i to r - 1
    ll calc(int l, int r, int x, int lx, int rx){
        if (r <= lx || rx <= l) return 0ll;
        if (l <= lx && rx <= r) return segtree[x];
        int m = (lx + rx) >> 1;
        ll res1 = calc(l, r, 2 * x + 1, lx, m);
        ll res2 = calc(l, r, 2 * x + 2, m, rx);
        return res1 + res2;
    }

    ll calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }


    // composing the structure of HLD
    // this function builds pos, head and segtree array
    // u -> current node, h -> head node;
    void compose(int u, int h){
        head[u] = h;
        pos[u] = curpos++;
        update(pos[u], a[u]);

        // checking if leaf node
        if(heavy[u] == -1) return;

        compose(heavy[u], h);
        for (int v: adj[u]){
            if (v == par[u] || v == heavy[u]) continue;
            compose(v, v);
        }
    }

    // path query from node u to node v
    // we calculate the greater depth head first until
    // both of the node's head is same
    // when both of the head is same, we can conclude that
    // one of them is the LCA
    ll query(int u, int v){
        ll res = 0;
        while (head[u] != head[v]){
            if (dep[head[u]] < dep[head[v]]) swap(u, v);
            res += calc(pos[head[u]], pos[u] + 1);
            u = par[head[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        res += calc(pos[u], pos[v] + 1);
        return res;
    }

};

void solve(ll tc){
    CASE(tc); cout << "\n";

    int n, u, v, type, i, x;
    cin >> n;
    HLD hld(n);
    for (int i = 0; i < n; i++){
        cin >> hld.a[i];
    }
    for (int i = 0; i < n - 1; i++){
        cin >> u >> v;
        hld.adj[u].PB(v);
        hld.adj[v].PB(u);
    }
    // dfs and compose on root node which is 0
    hld.dfs(0, 0);
    hld.compose(0, 0);

    int q;
    cin >> q;
    while(q--){
        cin >> type;
        if (!type){
            cin >> u >> v;
            cout << hld.query(u, v) << "\n";
        }
        else {
            cin >> i >> x;
            hld.update(hld.pos[i], x);
        }
    }

}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("inputf.in", "r", stdin);
    // freopen("outputf..out", "w", stdout);
    int i = 1;
    int t = 1;
    cin >> t;
    for(i = 1; i <= t; i++)
    solve(i);
    return 0;
}
