#include <iostream>
using namespace std;
    int MaxPile(vector<int>& arr){ // for finding the largest pile out of the whole
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++){
            maxi=max(arr[i],maxi);
        }
        return maxi;
    }
    long long TotalHours(vector<int>& piles, int speed) { // calculation of total hours to complete all the piles at a given speed 
        long long totalH = 0;
        for (int bananas : piles) {
            totalH += ceil((double)bananas / speed);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) { 
        int low=1,high=MaxPile(piles);
        while(low<=high){
            int mid=low+((high-low)/2);
            long long reqTime=TotalHours(piles,mid);
            if(reqTime>h) low= mid+1;
            else high=mid-1;
        }
        return low;
        
    }
