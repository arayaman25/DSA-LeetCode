#include <iostream>
using namespace std;

//TC: O(N^N) , SC : O(N)
class Solution {
public:

    int minJump(vector<int>& nums, int currIndex, int lastIndex , int jumps) {
        if (currIndex >= lastIndex) return jumps;
        int mini = INT_MAX;

        for (int i = 1; i <= nums[currIndex]; i++) {
            mini = min(mini, minJump(nums, currIndex + i , lastIndex , jumps + 1));
        }

        return mini;
    }

    int jump(vector<int>& nums) {
        return minJump(nums, 0, nums.size() - 1, 0);
    }
};

//----------------------------------------------------------------------------------------------------------------------------------------

//TC: O(N) , SC : O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int destination = n-1;
        int totalJumps = 0;
        int coverage = 0;
        int lastJumpInd = 0;

        if(n == 1) return 0;

        for(int i = 0 ; i < n ; i++){
            coverage = max(coverage , i + nums[i]);

            if(i == lastJumpInd){
                lastJumpInd = coverage;
                totalJumps++;

                if(coverage >= destination) return totalJumps;
            }
        }
        return totalJumps;
    }
};