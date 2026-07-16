#include <iostream>
using namespace std;
class Solution {
public:
//brute
    string revString(string s){
        int n = s.size();
        string s2 = "";
        for(int i = n - 1; i >= 0; i--){
            s2 += s[i];
        }
        return s2;
    }
    string binary(int n){
        string binary = "";
        while(n > 0){
            if(n % 2 == 1) binary += "1";
            else binary += "0";
            n = n / 2;
        }
        string s2 = revString(binary);
        return s2;
    }
    int minBitFlips(int start, int goal) {
        string sb = binary(start);
        string gb = binary(goal);
        int ns = sb.size();
        int ng = gb.size();
        int flips = 0;

        if(ns > ng){
            while(gb.size() < ns) gb = "0" + gb;
        } 
        else if(ng > ns){
            while(sb.size() < ng) sb = "0" + sb;
        }

        for(int i = 0; i < sb.size(); i++){
            if(sb[i] != gb[i]) flips++;
        }

        return flips;
    }
};

//--------------------------------------------------
 

//optimal

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n= start ^ goal;
        int count=0;
        while(n!=0){
            n=n & (n-1);
            count++;
        }
        return count;
    }
};

//--------------------------------------------------