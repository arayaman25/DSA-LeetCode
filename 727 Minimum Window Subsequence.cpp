#include<iostream>
using namespace std;

//brute     TC:O(m²)
class Solution {
public:
    string minWindow(string &s, string &t) {
        int m=s.size();
        int n=t.size();
        int minLen=INT_MAX;
        int ind=-1;

        for(int i=0;i<m;i++) {
            int k=0;
            for(int j=i; j<m; j++) {
                if(k<n && s[j]==t[k]) k++;
                if(k==n) {
                    if(j-i+1<minLen) {
                        minLen=j-i+1;
                        ind=i;
                    }
                    break;
                }
            }
        }
        if(ind==-1) return "";
        return s.substr(ind, minLen);
    }
};

//--------------------------------------------------