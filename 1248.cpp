#include <iostream>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int oddCnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2 != 0) oddCnt++;
                if(oddCnt==k) res++;
                if(oddCnt>k) break;
            }
        }
        return res;
    }
};

//optimal same as L(930)
int lessEqualSubarray(vector<int>& nums, int goal) {
        if(goal<0) return 0;
        int n = nums.size();
        int left = 0;
        int right=0;
        int count = 0;
        int sum=0;
        while(right<n) {
            sum+=nums[right]%2; //to convert odd to one and even to zero
            while(sum > goal) {
                sum-=nums[left]%2; //to convert odd to one and even to zero
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=lessEqualSubarray(nums,k)-lessEqualSubarray(nums,k-1);
        return count;
    }
