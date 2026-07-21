#include <iostream>
#include <vector>
using namespace std;
    int Maxi(vector<int>& arr){ 
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++){
            maxi=max(arr[i],maxi);
        }
        return maxi;
    }
    int Sum(vector<int>& arr){ 
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        return sum;
    }
bool possible(vector<int>& arr, int capacity, int days){
    int daysUsed = 1; //ship starts on day 1
    int load = 0;

    for(int w : arr){
        if(load + w > capacity){
            daysUsed++;
            load = w;
        } else {
            load += w;
        }
        if(daysUsed > days) return false;
    }
    return true;
}
    int BruteshipWithinDays(vector<int>& weights, int days) { //Brute approach
        int low=Maxi(weights),high=Sum(weights);
        for(int i=low;i<=high;i++){
            if(possible(weights,i,days)) return i;
        }
        return -1;        
    }
    int shipWithinDays(vector<int>& weights, int days) { //optimal with Binary
        int low=Maxi(weights),high=Sum(weights);
        int ans=-1;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(possible(weights,mid,days)) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;

        
    }