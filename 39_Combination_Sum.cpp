#include <iostream>
using namespace std;
class Solution {
public:
    void findCombination(int ind,vector<int>& candidates, int target ,vector<vector<int>> &ans, vector<int> &arr){
        if(ind==candidates.size()){
            if(target==0) ans.push_back(arr);
            return;
        }
        if(candidates[ind]<=target){
            arr.push_back(candidates[ind]);
            findCombination(ind,candidates,target-candidates[ind],ans,arr);
            arr.pop_back();
        }
        findCombination(ind+1,candidates,target,ans,arr);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        findCombination(0,candidates,target,ans,arr);
        return ans;
    }
};

//--------------------------------------------------