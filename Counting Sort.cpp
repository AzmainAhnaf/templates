// find the maximum value in a non negative vector;
int find_max(vector<int> a){
    int n = a.size();
    int mx = 0;
    for (int i = 0; i < n; i++) mx = max(mx, a[i]);
    return mx;
}

// calculate the prefix sum of a vector
vector<int> prefix_sum(vector<int> a){
    int n = a.size();
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++){
        pref[i] = pref[i - 1] + a[i];
    }
    return pref;
}

void countingsort(vector<int>& a){
    int mx = find_max(a);
    int n = a.size();
    vector<int> freq(mx + 1);
    for (int i = 0; i < n; i++){
        freq[a[i]]++;
    }
    freq = prefix_sum(freq);
    vector<int> b;
    for (int i = 0; i < n; i++) b.push_back(a[i]);
    for (int i = 0; i < n; i++){
        a[--freq[b[i]]] = b[i];
    }
}
