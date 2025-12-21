#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define PB push_back

struct Trie {
    struct Node {
        int next[26];
        int counter;
        Node () {
            for (int i = 0; i < 26; i++) next[i] = -1;
            counter = 0;
        }
    };
    vector<Node> adj;
    int idx;
    Trie () {
        adj.PB(Node());
        idx = 1; 
    }
    void insert(string &s){
        int cur = 0;
        for (char c: s){
            if (adj[cur].next[c - 'a'] == -1){
                adj[cur].next[c - 'a'] = idx++;
                adj.PB(Node());
            }
            cur = adj[cur].next[c - 'a'];
            adj[cur].counter++;
        }
    }
    int query(string &s){
        int cur = 0;
        for (char c: s){
            if (adj[cur].next[c - 'a'] == -1) return 0;
            cur = adj[cur].next[c - 'a'];
        }
        return adj[cur].counter;
    }
};

void solve(int tst){
    Trie trie;
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        trie.insert(s);
    }
    for (int i = 0; i < m; i++){
        cin >> s;
        cout << trie.query(s) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++){
        solve(i);
    }
    return 0;
}
