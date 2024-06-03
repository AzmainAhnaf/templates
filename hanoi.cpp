#include <bits/stdc++.h>

using namespace std;

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

// Type Names
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;


void print_moves(int start, int end){
	cout << start << " --> " << end << "\n";
}

void hanoi(int n, int start, int end){
	int others = 6 - (start + end);
	if (n == 1){
		print_moves(start, end);
	}
	else {
		hanoi(n - 1, start, others);
		print_moves(start, end);
		hanoi(n - 1, others, end);
	}
}

void solve()
{
    int n;
    cin >> n;
    hanoi(n, 1, 3);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //int t;
    //cin >> t;
    //for(int i = 0; i < t; i++)
    solve();
    return 0;
}
