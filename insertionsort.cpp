#include <bits/stdc++.h>

void insertionsort(vector<int>& a){
    int n = a.size();
    for (int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main(){
    return 0;
}
