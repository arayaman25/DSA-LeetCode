#include <iostream>
using namespace std;


//brute
class Solution {
public:
    int numberOfSubstrings(string s) {
       int n=s.size();
       int res=0;
       for(int i=0;i<n;i++){
        vector<int> freq(3,0);;
        for(int j=i;j<n;j++){
           freq[s[j]-'a']=1;
           if(freq[0]+freq[1]+freq[2]==3){
            res++;
           }
        }
       }
       return res; 
    }
};

//brute optimized
class Solution {
public:
    int numberOfSubstrings(string s) {
       int n=s.size();
       int res=0;
       for(int i=0;i<n;i++){
        vector<int> freq(3,0);;
        for(int j=i;j<n;j++){
           freq[s[j]-'a']=1;
           if(freq[0]+freq[1]+freq[2]==3){
            res+=n-j;
            break;
           }
        }
       }
       return res; 
    }
};

//optimal
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int res=0;
        vector<int> lastInd={-1,-1,-1};
        for(int i=0;i<n;i++){
            lastInd[s[i]-'a']=i;
            if(lastInd[1]>=0 && lastInd[2]>=0 && lastInd[0]>=0){
                res+=min(lastInd[0],min(lastInd[1],lastInd[2]))+1;
            }
        }
       return res; 
    }
};