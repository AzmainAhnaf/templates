// intro: this segment tree offers range updates, and range queries as well for
// the following kind of operations

#include <bits/stdc++.h>

using namespace std;

// calculate is only possible when the modify operation
// follows commutative and associative law for example below operation is possible
// because
// (a.v + b.v) = (a + b).v
// similarly this is also possible
// max(a + v, b + v) = max(a, b) + v
// ((a or v) and (b or v)) = (a and b) or v
// this way the operation should follow distributive property as well
// the modify operation should be the one that can be distributed properly

const long long MOD = 1e9 + 7;

struct segtree {

    int size;

    // values = original values
    // ops = operational quantity
    vector<long long> values, ops;

    long long NEUTRAL_VALUE = 0;

    // operation to mass change l to r
    long long modify_op(long long a, long long b){
        return (a * b) % MOD;
    }

    // operation to calculate something l to r
    long long calc_op(long long a, long long b){
        return (a + b) % MOD;
    }

    // applying modifying operation
    void apply_modify_op(long long &a, long long b){
        a = modify_op(a, b);
    }

    // building vector (may not needed, depending on the type of segtree)
    void build(int x, int lx, int rx){
        if (rx - lx == 1){
            values[x] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m);
        build(2 * x + 2, m, rx);
        values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
    }

    // initializing with proper size
    void init(int n){
        size = 1;
        while (size < n) size *= 2;
        values.assign(2 * size, 1);
        ops.assign(2 * size, 1);
        build(0, 0, size);
    }

    // modifying l to r with the value v
    void modify(int l, int r, long long v, int x, int lx, int rx){
        if (rx <= l || r <= lx) return;
        if (lx >= l && rx <= r){
            apply_modify_op(values[x], v);
            apply_modify_op(ops[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
        apply_modify_op(values[x], ops[x]);
    }

    void modify(int l, int r, long long v){
        modify(l, r, v, 0, 0, size);
    }

    // calculating l to r
    long long calc(int l, int r, int x, int lx, int rx){
        if (rx <= l || r <= lx) return NEUTRAL_VALUE;
        if (lx >= l && rx <= r){
            return values[x];
        }
        int m = (lx + rx) / 2;
        long long s1 = calc(l, r, 2 * x + 1, lx, m);
        long long s2 = calc(l, r, 2 * x + 2, m, rx);
        long long res = calc_op(s1, s2);
        apply_modify_op(res, ops[x]);
        return res;
    }

    long long calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

};

int main() {
    return 0;
}
