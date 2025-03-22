#include <bits/stdc++.h>

// print vector X)
void print_vector(vector<int> a){
    int n = a.size();
    for (int i = 0; i < n; i++){
        cout << a[i] << (i == n - 1 ? "\n" : " ");
    }
}

// find the partition point in a quicksort (also sort the array in the process)
int partition(vector<int>& a, int lo, int hi){
    // setting the last element of the array as pivot
    int pivot = a[hi];

    // pointer to the partition point
    int i = lo;

    // swapping take place if element lower than pivot is found
    for (int j = i; j < hi; j++){
        if (a[j] <= pivot){
            swap(a[i], a[j]);
            i++;
        }
    }

    // final swap with the pivot
    swap(a[hi], a[i]);

    return i;
}

// quicksort using partition
void quicksort(vector<int>& a, int lo, int hi){
    if (lo < hi){
        // finding the partition of current array (sub-array)
        int pi = partition(a, lo, hi);
        // splitting them into two sub arrays
        quicksort(a, lo, pi - 1);
        quicksort(a, pi + 1, hi);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    print_vector(a);
    quicksort(a, 0, n - 1);
    print_vector(a);
    return 0;
}
