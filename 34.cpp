#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

 int LowerBound(vector<int>&nums,int n,int target){
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    int UpperBound(vector<int>&nums,int n,int target){
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(nums[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=LowerBound(nums,n,target);
        if(lb==n || nums[lb]!=target) return {-1,-1};
        return {lb,UpperBound(nums,n,target)-1};
    }

    // other method below

    int first(vector<int>&nums,int n,int target){
        int low=0,high=n-1;
        int first=-1;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return first;
    }
    int last(vector<int>&nums,int n,int target){
        int low=0,high=n-1;
        int last=-1;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        return {first(nums,n,target),last(nums,n,target)};
    }

int main(){
    return 0;
}