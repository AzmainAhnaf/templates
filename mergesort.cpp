#include <bits/stdc++.h>

void merge(vector<int>& a, int l, int m, int r){
    // sizes of the two arrays that need to get merged
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> b(n1), c(n2);
    // assigning values to both the arrays
    for (int i = 0; i < n1; i++){
        b[i] = a[l + i];
    }

    for (int i = 0; i < n2; i++){
        c[i] = a[m + 1 + i];
    }

    // three pointers
    int i = 0;
    int j = 0;
    int k = l;

    // merging in the main array
    while (i < n1 && j < n2){
        if (b[i] <= c[j]){
            a[k] = b[i];
            i++;
        }
        else {
            a[k] = c[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        a[k] = b[i];
        i++;
        k++;
    }

    while (j < n2){
        a[k] = c[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& a, int l, int r){
    if (l < r){
        // dividing array in half
        int m = l + (r - l) / 2;

        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);

        // merging both arrays
        merge(a, l, m, r);
    }
}
