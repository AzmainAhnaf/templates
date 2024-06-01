#include <bits/stdc++.h>

using namespace std;

// Make a prefix sum array --> O(N)
vector<long long> make_prefix_sum_array(vector<int> nums){
    vector<long long> ans(nums.size() + 1);
    for (int i = 0; i < nums.size(); i++){
        ans[i + 1] = ans[i] + nums[i];
    }
    return ans;
}

long long range_sum_array(int l, int r, vector<long long> prefix){
    return prefix[r] - prefix[l - 1];
}

int main(){
    return 0;
}
