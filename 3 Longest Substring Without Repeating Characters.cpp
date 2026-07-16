#include <iostream>
#include <vector>
#include <map>
#include <map>
#include <unordered_set>
using namespace std;

  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxi = 0;

    for (int i = 0; i < n; i++) {
        string s2;
        for (int j = i; j < n; j++) {
            if (s2.find(s[j]) != string::npos) break;
            s2.push_back(s[j]);
            maxi = max(maxi, j - i + 1);
        }
    }

    return maxi;
        
    }

int lengthOfLongestSubstring2(string s) {
       
    unordered_set<char> seen;
    int left = 0; 
    int ans = 0;

    for (int right = 0; right< s.size(); right++) { 
        while (seen.count(s[right])) { 
          
            seen.erase(s[left]);
            left++;
        }

        seen.insert(s[right]); 
        ans = max(ans, right - left+ 1); 
    }

    return ans;
}

//sliding wi
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();

        int hash[256]; 
        for(int i= 0; i<256; i++) { 
            hash[i] = -1;
        }
        int maxLen=0;
        int l=0,r=0;
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }

            int len=r-l+1;
            maxLen=max(maxLen,len);

            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};

//--------------------------------------------------
