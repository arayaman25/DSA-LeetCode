#include<iostream>
using namespace std;

//brute
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int flips=0;
            for(int j=i;j<n;j++){
                if(nums[j]==0) flips++;
                if(flips>k) break;
                maxi=max(maxi,j-i+1);
            }

        }
        return maxi;
    }
};

//--------------------------------------------------

//better O(2n)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        int l=0,r=0,flips=0;
        while(r<n){
            if(nums[r]==0) flips++;
            while(flips>k){
                if(nums[l]==0) flips--;
                l++;
            }
            if(flips<=k) maxi=max(maxi,r-l+1);
            r++;;
            
        }
        return maxi;
    }
};

//--------------------------------------------------

//optimized O(n)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        int l=0,r=0,flips=0;
        while(r<n){
            if(nums[r]==0) flips++;
            if(flips>k){
                if(nums[l]==0) flips--;
                l++;
            }
            else{
                maxi=max(maxi,r-l+1);
            }
            r++;;
            
        }
        return maxi;
    }
};

//--------------------------------------------------