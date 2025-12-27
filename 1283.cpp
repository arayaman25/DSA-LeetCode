#include <iostream>
using namespace std;
    int Maxi(vector<int>& arr){ 
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++){
            maxi=max(arr[i],maxi);
        }
        return maxi;
    }
    bool calc(vector<int>& arr,int divisor,int thresh){
        long long sum=0;
        for(int number:arr){
            sum+=ceil((double)number / divisor);
            if(sum > thresh) return false;
        }
        if(sum<=thresh) return true;
        else return false;
    }
    int Brute_smallestDivisor(vector<int>& nums, int threshold) { //brute
        int low=1,high=Maxi(nums);
        for(int div=low;div<=high;div++){
            if(calc(nums,div,threshold)) return div;
            
        }
        return -1;      
    }
    int smallestDivisor(vector<int>& nums, int threshold) { //optimal binary search
        int low=1,high=Maxi(nums);
        int ans=-1;
        while(low<=high){
            int mid=low+((high-low)/2);
            bool check=calc(nums,mid,threshold);
            if(check){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;

        
    }
