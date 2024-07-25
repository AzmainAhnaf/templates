#include <bits/stdc++.h>

void bubblesort(vector<int>& a){
    int n = a.size();
    for (int i = 0; i < n; i++){
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
