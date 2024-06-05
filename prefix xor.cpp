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

ll summation(ll n){
	return (n * (n - 1)) / 2;
}

void solve()
{
	int n;
	cin >> n;
	vi num(n), prefix_xor(n);
	for (int i = 0; i < n; i++) cin >> num[i];
	prefix_xor[0] = num[0];
	for (int i = 1; i < n; i++){
		prefix_xor[i] = prefix_xor[i - 1] ^ num[i];
	}
	for (auto i: prefix_xor){
		cout << i << " ";
	}
	cout << "\n";
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
