#include <iostream>
using namespace std;
const long long MOD = 1e9 + 7;

    long long helperPow(long long x, long long p){
        if(p == 0) return 1;

        if(p % 2 == 1) return (x * helperPow(x , p - 1)) % MOD;
        long long half = helperPow(x , p / 2);
        return (half * half) % MOD;
    }

    long long myPow(long long x, long long n) {
        return helperPow(x , n);
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long x = (myPow(5 , even) * myPow(4 , odd)) % MOD;

        return x;
    }