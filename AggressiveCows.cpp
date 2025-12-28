#include <iostream>
using namespace std;
    bool possible(vector<int> &nums,int dist, int k){
        int cowCount=1,last=nums[0];
        for(int i=1;i<nums.size();i++){
            if (nums[i] - last >= dist){
                cowCount++;
                last=nums[i];
            }
        }
        if(cowCount>=k) return true;
        else return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=nums[n-1]-nums[0];
        while(low<=high){
           int mid=low+(high-low)/2;
            if(possible(nums,mid,k)) low=mid+1;
            else high=mid-1;
        }
        return high;

        
    }
