// Problem Name: UnionFind
// Problem Link: https://judge.yosupo.jp/problem/unionfind

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

struct DSU {

    vector<int> p, size;

    DSU(int n){
        p.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) p[i] = i;
    }

    int get(int a){
        if (a == p[a]) return a;
        return p[a] = get(p[a]);
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);
        if (a != b){
            if (size[a] < size[b]) swap(a, b);
            p[b] = p[a];
            size[a] += size[b];
        }
    }

};

void solve(int tc){
    int n, q;
    cin >> n >> q;
    DSU dsu(n);

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