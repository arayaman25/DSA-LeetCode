
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int ng = -1;

            for(int j = 1; j < n; j++) {
                int idx = (i + j) % n;
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