#include<bits/stdc++.h>

using namespace std;

class DSU {
public:

    vector<int> p;
    vector<int> rank;

    DSU(int n){
        p.resize(n + 1);
        rank.assign(n + 1, 0);
        REP(i, 1, n + 1) p[i] = i;
    }

    int get(int a){
        if (a != p[a]){
            p[a] = get(p[a]);
        }
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);
        if (a != b){
            if (rank[a] < rank[b]) swap(a, b);
            if (rank[a] == rank[b]) rank[a]++;
            p[b] = a;
        }
    }


};

void solve(ll tc){
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    while(q--){
        string act;
        cin >> act;
        if (act == "get"){
            int a, b;
            cin >> a >> b;
            cout << (dsu.get(a) == dsu.get(b) ? "YES\n": "NO\n");
        }
        else {
            int a, b;
            cin >> a >> b;
            dsu.merge(a, b);
        }
    }
}

int main(){
    solve();
}