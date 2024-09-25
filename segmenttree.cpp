#include <bits/stdc++.h>

using namespace std;

struct segtree {

    int size;
    vector<long  long> sums;

    // initializing the segtree with the size of elements = n
    void init(int n){
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0ll);
    }

    // a = initializer vector
    // x = current index
    // lx, rx = range of the current index
    void build(vector<int> &a, int x, int lx, int rx){
        if (rx - lx == 1){
            if (lx < a.size()){
                sums[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    // building segtree using initializer vector
    void build(vector<int> &a){
        build(a, 0, 0, size);
    }

    // i = index, v = value
    // x = current index
    // lx, rx = range of the current index
    void set(int i, int v, int x, int lx, int rx){
        if (rx - lx == 1){
            sums[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m){
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    // sets index i to v and update the tree
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    // l, r = range of the sum [l, r - 1]
    // x = current index
    // lx, rx = range of the current index
    long long sum(int l, int r, int x, int lx, int rx){
        if (l >= rx || lx >= r) return 0ll;
        if (lx >= l && rx <= r) return sums[x];
        int m = (lx + rx) / 2;
        long long s1 = sum(l, r, 2 * x + 1, lx, m);
        long long s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    // sums of all the indices from l to r - 1
    long long sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }

    // printing the whole tree (sums) array
    void print_tree(){
        for (auto a: sums){
            cout << a << " ";
        }
        cout << "\n";
    }
};

int main(){
    return 0;
}
