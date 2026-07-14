#include <iostream>
using namespace std;
    double myPow(double x, int n) { //O(log n)
        if(n==0) return 1;

        long long p = n;
        if(p < 0){
            x = 1 / x;
            p = -p;
        }

        double res=1.0;
        while(p > 0){
            if(p % 2 == 1)
                res *= x;

            x *= x;
            p /= 2;
        }
        return res;

    }

    double helperPow(double x,long long p){ // recursive
        if(p==0) return 1;
        if(p==1) return x;
        if(p % 2 == 1) return (x * helperPow(x , p-1));
        return helperPow(x * x , p/2);

    }
    double myPow(double x, int n) {
        if(n==0) return 1;

        long long p = n;
        if(p < 0){
            x = 1 / x;
            p = -p;
            return helperPow(x ,p);
        }
        return helperPow(x ,  p);
    }