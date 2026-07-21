#include <iostream>
using namespace std;

// TC : O(N)
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        int preZero = 0 , currZero = 0;
        int maxSum = 0;

        int i = 0;
        while(i < n) {
            if(s[i] == '1'){
                ones++;
                i++;
            }
            else{
                currZero = 0;
                while(i < n && s[i] == '0'){
                    currZero++;
                    i++;
                }
                if(preZero) maxSum = max(maxSum, preZero + currZero);
                preZero = currZero;
            }
        }
        int ans = ones + maxSum;
        return ans;
    }
};