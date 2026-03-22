#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    void powerSet(vector<int>& nums ,int n, vector<vector<int>>& result ,int ind , vector<int>& ds ){
        if(ind>=n){
            result.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        powerSet(nums,n, result, ind + 1, ds);
        ds.pop_back();
        powerSet(nums,n, result, ind + 1, ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> result;
        vector<int> ds;
        powerSet(nums,n,result,0,ds);
        return result;
    }
};