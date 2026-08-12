#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int l = 0;
        int maxLen = INT_MIN;
        for(int r = 0; r < n ; r++){
            freq[nums[r]]++;
            while(freq[nums[r]] > k){
                freq[nums[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l +1);
        }
        return maxLen;
    }
};