#include <iostream>
using namespace std;

//Brute - recursion
// TC :O(2^n) SC :O(n)
class Solution {
public:
    bool isValid(vector<int>& nums, int currIndex, int lastIndex) {
        if (currIndex >= lastIndex) return true;

        for (int jump = 1; jump <= nums[currIndex]; jump++) {
            if (isValid(nums, currIndex + jump, lastIndex))
                return true;
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        return isValid(nums, 0, nums.size() - 1);
    }
};

//--------------------------------------------------


//TC :O(n) SC :O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxInd=0;

        for(int i = 0 ; i < n ; i++){
            if( i > maxInd ) return false;

            maxInd = max(maxInd, i + nums[i]);
        }
        return true;
    }
};

//--------------------------------------------------