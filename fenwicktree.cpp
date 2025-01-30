#include <bits/stdc++.h>

using namespace std;


// 1-indexed Fenwick tree or BIT(Binary Indexed Tree)
class BIT {
public:

    int n;
    vector<long long> bit;

    BIT(int n){
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // Constructing the tree in linear complexity
    BIT(vector<long long> const &a) : BIT(a.size()) {
        for (int i = 1; i <= n; i++){
            bit[i] += a[i];
            int r = i + (i & -i);
            if (r <= n) bit[r] += bit[i];
        }
    }

    // adding delta to the index idx
    void add(int idx, long long delta){
        while (idx <= n){
            bit[idx] += delta;
            idx += (idx & -idx);
        }
    }

    // calculating sum of range [1, r]
    long long sum(int r){
        long long res = 0;
        while (r > 0){
            res += bit[r];
            r -= (r & -r);
        }
        return res;
    }

    // calculating sum or range [l, r]
    long long sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
};

int main(){
    // n = number of elements in the array
    // q = number of queries
    int n, q;
    cin >> n >> q;
    // 1-indexed array
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    BIT bit(a);
    // 2 query types
    // 1 i v -> raise value v of the element at index i
    // 2 l r -> calculate sum in the range [l, r]
    while(q--){
        int act;
        cin >> act;
        if (act == 1){
            int i; long long v;
            cin >> i >> v;
            bit.add(i, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << bit.sum(l, r) << "\n";
        }
    }
    return 0;
}
