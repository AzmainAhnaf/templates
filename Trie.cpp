// Problem Name: Ada and Indexing
// Problem Link: https://www.spoj.com/problems/ADAINDEX/

#include <bits/stdc++.h>
 
using namespace std;
 
// Macros
#define REP(i, j, n) for(int i = j; i < n; i++)

struct TrieNode {

    TrieNode *children[26];
    int counter;

    TrieNode(){
        counter = 0;
        for (int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }

};

void insert(TrieNode *root, const string &key){

    TrieNode *curr = root;

    for (char c: key){
        if (curr->children[c - 'a'] == nullptr){
            TrieNode *newNode = new TrieNode();
            curr->children[c - 'a'] = newNode;
        }
        curr = curr->children[c - 'a'];
        curr->counter++;
    }
} 

int query(TrieNode *root, const string &key){

    TrieNode *curr = root;

    for (char c: key) {
        if (curr->children[c - 'a'] == nullptr) return 0;
        curr = curr->children[c - 'a'];
    }
    return curr->counter;
}

void solve(int tc){

    int n, m;
    cin >> n >> m;

    string s;
    TrieNode *root = new TrieNode();

    REP(i, 0, n) {
        cin >> s;
        insert(root, s);
    }

    REP(i, 0, m){
        cin >> s;
        cout << query(root, s) << "\n";
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
