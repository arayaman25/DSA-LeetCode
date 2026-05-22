#include <iostream>
using namespace std;
//brutee
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int ng = -1;

            for(int j = i+1; j <= i+n-1 ; j++) {
                int idx = j % n;
                if(nums[idx] > nums[i]) {
                    ng = nums[idx];
                    break;
                }
            }
            res.push_back(ng);
        }
        return res;
    }
};