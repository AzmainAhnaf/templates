int find_max(vector<int> a, int n){
    int mx = 0; // considering all the number are positive in the vector
    for (int i = 0; i < n; i++){
        mx = max(mx, a[i]);
    }
    return mx;
}

void countingsort(vector<int>& a, int n, int place){
    vector<int> output(n);
    vector<int> count(10);

    for (int i = 0; i < n; i++){
        count[(a[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++){
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--){
        output[count[(a[i] / place) % 10] - 1] = a[i];
        count[(a[i] / place) % 10]--;
    }
    a = output;
}

void radixsort(vector<int>& a, int n){
    int mx = find_max(a, n);

    for (int place = 1; mx / place > 0; place *= 10){
        countingsort(a, n, place);
    }
}

int main(){
    vector<int> a{121, 1, 432, 23, 564, 45, 788}
    radixsort(a, a.size());
    return 0;
}
