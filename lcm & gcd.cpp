#include<bits/stdc++.h>

// slower than built in __gcd() function
// recursive approach
int gcd1(int a, int b){
    if (a == 0) return b;
    else if (b == 0) return a;
    else if (a == b) return a;
    else if (a > b) return gcd1(a - b, b);
    else return gcd1(a, b - a);
}

// iterative approach
int gcd2(int a, int b){
    if (a == 0) return b;
    else if (b == 0) return a;
    while(a != b){
        if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

int lcm(int a, int b){
    return (a * b) / gcd1(a, b);
}