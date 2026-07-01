#include <iostream>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int dist=0;
            vector<int> hash(26,0);
            for(int j=i;j<n;j++){
                if(hash[nums[j]]==0) dist++;
                hash[nums[j]]++;
                if(dist==k) count++;
                if(dist>k) break;
                
            }
        }
        return count;
    }
};



//optimal
class Solution {
public:

    int lessEqualSubarray(vector<int>& nums, int k) {
        if(k<0) return 0;
        int n = nums.size();
        int left = 0;
        int right=0;
        int count = 0;
        unordered_map<int,int> mp;
        while(right<n) {
            mp[nums[right]]++;
            while(mp.size() > k) {
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int count=lessEqualSubarray(nums,k)-lessEqualSubarray(nums,k-1);
        return count;
    }
};