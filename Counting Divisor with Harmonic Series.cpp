#include <bits/stdc++.h>

using namespace std;

int main(){
    const int N = 1e6;
    vector<int> numbers(N);
    // This double for loop would take O(nlogn) [Linearithmic]
    for (int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            numbers[j]++;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << numbers[n] << "\n";
    }
}
