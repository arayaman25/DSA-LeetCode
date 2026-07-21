#include<iostream>
using namespace std;
    int Maxi(vector<int>& arr){ 
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++){
            maxi=max(arr[i],maxi);
        }
        return maxi;
    }
    int Summ(vector<int>& arr){ 
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        return sum;
    }
    bool possible(vector<int>& arr,int k,int ls){
        int sum=0,count=1;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>ls){
                count++;
                sum=arr[i];
            }
            else sum+=arr[i];
            if(count>k) return false;

        }
        return true; //at most k subarrays
        
    }
    int splitArray(vector<int>& nums, int k) {
        int low=Maxi(nums),high=Summ(nums);
        for(int i=low;i<=high;i++){
            if(possible(nums,k,i)) return i;

        }
        return -1;
        
    }
