#include <bits/stdc++.h>

using namespace std;

// maxK = sum of the whole array
const int maxK = 1e5;

int main(){
	int n;
	cin >> n;
	// storing frequency for every number in the array
	vector<int> freq(maxK + 1);
	for (int i = 0; i < n; i++){
		int ph;
		cin >> ph;
		freq[ph]++;
	}
	// store the freq in (a, m) format
	// a = value
	// m = frequency
	vector<pair<int, int>> compressed;
	for (int i = 1; i <= maxK; i++){
		if (freq[i] > 0){
			compressed.push_back(make_pair(i, freq[i]));
		}
	}
	bitset<maxK + 1> dp;
	dp[0] = 1;
	for (int i = 0, size = compressed.size(); i < size; i++){
		int a = compressed[i].first, m = compressed[i].second;
		for (int x = 0; (1 << x) <= m; x++){
			dp |= (dp << (a * (1 << x)));
			m -= (1 << x);
		}
		dp |= (dp << (a * m));
	}
	cout << "Subset sums: \n";
	for (int i = 0; i <= maxK; i++){
		if (dp[i]) cout << i << " ";
	}
	cout << "\n";
}