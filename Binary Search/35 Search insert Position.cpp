#include<iostream>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low =0,high=n-1;
        bool ans=false;
        int ans2=0;
        while(low<=high){
             int mid=low+((high-low)/2);
            if(nums[mid]==target){
                ans2=mid;
                ans=true;
                break;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        if(!ans){
            ans2=lower_bound(nums.begin(),nums.end(),n)-nums.begin();
        }
        return ans2;
    }
     
int main(){
    return 0;
}