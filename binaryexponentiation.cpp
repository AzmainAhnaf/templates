#include <iostream>

using namespace std;

long long power(long long a, long long b, long long m)
{
    long long res = 1 % m;
    a %= m;
    if (a < 0) a += m;
    while(b)
    {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// if we want to apply fermat's little theorem to calculate inverse of a number mod m
// we need to pass these as arguments of power function -> power(number, m - 2, m) {m has to be prime}

int main()
{
    long long a, b;
    const long long m = 1e9 + 7;
    cin >> a >> b;
    // calculating a^b mod m
    long long res = power(a, b, m);
    cout << res << "\n";
}
