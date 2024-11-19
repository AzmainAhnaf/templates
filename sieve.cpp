#include <bits/stdc++.h>

using namespace std;


vector<bool> sieve(int n){
    vector<bool> prime(n + 1, true);
    prime[1] = false;
    for (int i = 2; i <= n; i++){
        if (prime[i] && (long long)(i * i) <= n){
            for (int j = i * i; j <= n; j += i){
                prime[j] = false;
            }
        }
    }
    return prime;
}

vector<int> divisor_sieve(int n){
    vector<int> res(n + 1, 1);
    for (int i = 2; i <= n; i++){
        for (int j = i; j <= n; j += i){
            res[j]++;
        }
    }
    return res;
}

vector<int> divisor_sum_sieve(int n){
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j += i){
            res[j] += i;
        }
    }
    return res;
}

vector<int> euler_totient_sieve(int n){
    vector<int> totient(n + 1);
    for (int i = 1; i <= n; i++) totient[i] = i;
    for (int i = 2; i <= n; i++)
        if (totient[i] == i)
            for (int j = i; j <= n; j += i)
                totient[j] -= totient[j] / i;
    return totient;
}

vector<int> biggest_prime_divisor_sieve(int n){
    vector<int> big(n + 1, 1);
    for (int i = 2; i <= n; i++){
        if (big[i] == 1){
            for (int j = i; j <= n; j += i){
                big[j] = i;
            }
        }
    }
    return big;
}


int main()
{
    int n;
    cin >> n;
    vector<bool> res = sieve(n);
    for (int i = 1; i <= n; i++){
        cout << i << " " << res[i] << "\n";
    }
}
