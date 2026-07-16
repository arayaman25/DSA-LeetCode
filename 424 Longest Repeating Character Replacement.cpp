#include<iostream>
using namespace std;

//O(n^2)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxi=0;
        
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            int maxf=0;
            for(int j=i;j<n;j++){
                freq[s[j]-'A']++;
                maxf=max(maxf,freq[s[j]-'A']);
                int changes=(j-i+1)-maxf;
                if(changes<=k) maxi=max(maxi,j-i+1);
                else break;
            }
        }
        return maxi;
    }
};

//--------------------------------------------------

//O(N)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxi=0;
        int l=0,r=0;
        vector<int> freq(26,0);
        int maxf=0;
        for(r=0;r<n;r++){
            freq[s[r]-'A']++;
            maxf=max(maxf,freq[s[r]-'A']);
            int changes=(r-l+1)-maxf;
            if(changes>k){
                freq[s[l]-'A']--;
                l++;
            }
            maxi=max(maxi,r-l+1);

        }
        return maxi;
    }
};

//--------------------------------------------------