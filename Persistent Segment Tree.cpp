// Solution to problem: Make Versions in Segment Tree
// Problem Link: https://www.spoj.com/problems/PSEGTREE/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<long long> vll;

const int nsz = 100010;
const int qsz = 6000010; // n + qlogn

int T = 1;

ll a[nsz] = {};
ll version[nsz] = {};
ll Left[qsz] = {}, Right[qsz] = {}, val[qsz] = {};


// building initial version 0 segment tree
void build(vector<ll> &a, int node, int lx, int rx){
    if (rx == lx){
        if (lx < a.size()){
            val[node] = a[lx];
        }
        else {
            val[node] = 0ll;
        }
        return;
    }

    // assigning a node to left and right child
    Left[node] = T++;
    Right[node] = T++;

    // recursively building left and right child
    int m = (lx + rx) >> 1;
    build(a, Left[node], lx, m);
    build(a, Right[node], m + 1, rx);
    val[node] = val[Left[node]] + val[Right[node]];
}

// adding v to index i of version node and creating a new version
int update(int node, int lx, int rx, int i, ll v){
    if (rx < i || lx > i){
        return node;
    }

    int nnode = T++;

    if (lx == rx){
        val[nnode] = val[node];
        val[nnode] += v;
        return nnode;
    }

    int m = (lx + rx) >> 1;
    Left[nnode] = update(Left[node], lx, m, i, v);
    Right[nnode] = update(Right[node], m + 1, rx, i, v);

    val[nnode] = val[Left[nnode]] + val[Right[nnode]];
    return nnode;
}

// calculating sum of index l to r of version node segment tree
ll calc(int node, int lx, int rx, int l, int r){
    if (rx < l || r < lx) return 0ll;
    if (l <= lx && rx <= r) return val[node];

    int m = (lx + rx) >> 1;

    return calc(Left[node], lx, m, l, r) + calc(Right[node], m + 1, rx, l, r);
}


void solve(ll tc){   
    int n, type;
    cin >> n;
    vll a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int size = 1;
    while (size <= n) size *= 2;
    build(a, version[0], 1, size);
    int q;
    cin >> q;
    int cur = 1;
    while(q--){
        cin >> type;
        if (type == 2){
            int v, l, r;
            cin >> v >> l >> r;
            cout << calc(version[v], 1, size, l, r) << "\n";
        }
        else {
            int ver, i; ll v;
            cin >> ver >> i >> v;
            version[cur++] = update(version[ver], 1, size, i, v);
        }
    }
    // cout << "WORKS\n";
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int i = 1;
    // int t = 1;
    // cin >> t;
    // for(i = 1; i <= t; i++)
    solve(i);
    return 0;
}    