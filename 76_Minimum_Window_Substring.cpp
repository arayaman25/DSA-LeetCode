#include <iostream>
#include <vector>
using namespace std;

//Brute TC:0(n^2) SC:O(256)
class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        int minLen=INT_MAX;
        int ind=-1;
        for(int i=0;i<m;i++){
            vector<int> hash(256,0);
            int count=0;
            for(int j=0;j<n;j++) hash[t[j]]++;

            for(int j=i;j<m;j++){
                if(hash[s[j]]>0) count++;
                hash[s[j]]--;

                if(count==n){
                    if(j-i+1<minLen){
                        minLen=j-i+1;
                        ind=i;
                        break;
                    }
                }
            }
        }
        if(ind== -1) return "";
        string ans=s.substr(ind,minLen);
        return ans;
    }
};


//optimal     TC: O(m+n)  SC: O(256) 
class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        int l=0,r=0;
        int minLen=INT_MAX;
        int ind=-1;
        int count=0;

        vector<int> hash(256,0);
        for(int j=0;j<n;j++) hash[t[j]]++;

        while(r<m){
            if(hash[s[r]]>0) count++;
            hash[s[r]]--;

            while(count==n){
                if(r-l+1 < minLen){
                    minLen=r-l+1;
                    ind=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) count--;
                l++;
            }
            
            r++;

        }
        if(ind== -1) return "";
        string ans=s.substr(ind,minLen);
        return ans;
    }
};