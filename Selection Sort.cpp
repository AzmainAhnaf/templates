#include <bits/stdc++.h>

// O(N^2)
void selectionsort(vector<int>& a){
    int n = a.size();
    for (int i = 0; i < n; i++){
        int min_idx = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[min_idx]){
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
}

int main(){
    return 0;
}
