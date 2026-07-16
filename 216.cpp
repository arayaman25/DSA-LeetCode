#include <iostream>
using namespace std;
class Solution {
public:
    void findCombination(int k, int n , int m,int num, vector<vector<int>>& ans,vector<int>& ds){
        if (m==k) {
            if (n==0) ans.push_back(ds);
            return;
        }
        for(int i=num;i<=9;i++){
            if (i > n) break;

            ds.push_back(i);
            findCombination(k,n-i,m+1,i+1,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(k,n,0,1,ans,ds);
        return ans;
    }
};

//--------------------------------------------------