#include <bits/stdc++.h>
#include <vector>

using namespace std;

// get the left most index of the specified number in a sorted array
// return -1 if not found
int binary_search_left_index(vector<int> a, int target, int sz){
	int l = 0;
	int r = sz - 1;
	int ans = -1;
	while (l <= r){
		int mid = l + ((r - l) / 2);
		if (a[mid] == target){
			ans = mid;
			r = mid - 1;
		}
		else if (a[mid] < target){
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return ans;
}
