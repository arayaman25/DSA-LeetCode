#include<iostream>
using namespace std;
    int Maxi(vector<int>& arr){ 
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++){
            maxi=max(arr[i],maxi);
        }
        return maxi;
    }
    int Mini(vector<int>& arr){ 
        int mini=arr[0];
        for(int i=1;i<arr.size();i++){
            mini=min(arr[i],mini);
        }
        return mini;
    }
    bool possible(vector<int>& arr,int day,int m,int k){
        int count=0;long long bqt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day) count++;
            else{
                bqt+=(count/k);
                count=0;
            }
        }
        bqt+=(count/k);
        if(bqt>=m) return true;
        else return false;
        
    }
    int Brute_minDays(vector<int>& bloomDay, int m, int k) { //brute
        if(bloomDay.size()<(m*k)) return -1;//edge case
        int low=Mini(bloomDay),high=Maxi(bloomDay);
        for(int day=low;day<=high;day++){
            bool check=possible(bloomDay,day,m,k);
            if(check) return day;
            
        }
        return -1;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {//optimized with binary
        if(bloomDay.size()<(long long)m*k) return -1;
        int low=Mini(bloomDay),high=Maxi(bloomDay);
        int minDay=0;
        while(low<=high){
            int mid=low +((high-low)/2);
            bool check=possible(bloomDay,mid,m,k);
            if(check){
                minDay=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return minDay;
    }
