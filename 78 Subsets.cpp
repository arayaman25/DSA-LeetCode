#include <iostream>
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

//--------------------------------------------------

//bit wise
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subsets= 1 << n;
        vector<vector<int>> result;
        for(int counter=0 ; counter < subsets ; counter++){
            vector<int> ds;
            for(int i=0; i < n ; i++){
                 if( (counter & (1 << i)) != 0) ds.push_back(nums[i]);
            }
            result.push_back(ds);
        }
        return result;
    }
};

//--------------------------------------------------