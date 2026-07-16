#include <iostream>
using namespace std;
class Solution {
public:
    void powerSet(vector<int>& nums , vector<vector<int>>& result ,int ind , vector<int>& ds ){
        result.push_back(ds);
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1]) continue; // skip duplicates

            ds.push_back(nums[i]);
            powerSet(nums, result, i + 1, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> ds;
        powerSet(nums,result,0,ds);
        return result;
    }
};

//--------------------------------------------------