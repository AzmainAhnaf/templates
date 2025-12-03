// Problem Name: Ada and Indexing
// Problem Link: https://www.spoj.com/problems/ADAINDEX/

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
#define CASE(i) cout << "Case #" << i << ": ";
#define MEM(arr, val) memset(arr, val, sizeof(arr));
 
// Type Names
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pld;
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
const ld EPS = 1e-6;

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
