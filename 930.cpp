#include<iostream>
using namespace std;

//brute
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==goal){
                    count++;
                    continue;
                } 
                
            }
        }
        return count;
    }
};



//could be done using the subarray sum equals k approch Q560

//optmal TC-O(n) SC-O(1)
int lessEqualSubarray(vector<int>& nums, int goal) {
        if(goal<0) return 0;
        int n = nums.size();
        int left = 0;
        int right=0;
        int count = 0;
        int sum=0;
        while(right<n) {
            sum+=nums[right];
            while(sum > goal) {
                sum-=nums[left];
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=lessEqualSubarray(nums,goal)-lessEqualSubarray(nums,goal-1);
        return count;
    }