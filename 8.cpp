#include <iostream>
#include <vector>
using namespace std;
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        long long num = 0;
        int sign = 1;

        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            // Overflow handling
            if (num * sign >= INT_MAX) return INT_MAX;
            if (num * sign <= INT_MIN) return INT_MIN;
            i++;
        }

        return num * sign;
    }


        int recFun(string s,int n,int i,long long num,int sign){
        if(i>=n || !isdigit(s[i])) return (int)(sign*num);
        num = num * 10 + (s[i] - '0');
        if (num * sign >= INT_MAX) return INT_MAX;
        if (num * sign <= INT_MIN) return INT_MIN;
        i++;
        return recFun(s,n,i,num,sign);

    }
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        long long num = 0;
        int sign = 1;

        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        return recFun(s,n,i,0,sign);

    }
