#include <bits/stdc++.h>

using namespace std;

// returns a string of size sz which is the binary representation of integer n
string int_to_binary(int n, int sz){
    string bin = "";
    while (n != 0){
        int next = n % 2;
        bin = to_string(next) + bin;
        n /= 2;
    }
    while (bin.size() < sz){
        bin = '0' + bin;
    }
    return bin;
}

void print_every_combination(int n){
    for (int i = 0; i < (1 << n); i++){
        string s = int_to_binary(i, n);
        cout << s << "\n";
    }
}

int main(){
    print_every_combination(5);
}
