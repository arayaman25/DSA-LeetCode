#include<iostream>
#include<map>
#include<vector>

using namespace std;

int subarraysWithXorK(vector<int> &nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int xorr=0;
            for(int j=i;j<n;j++){
                xorr^=nums[j];
                if(xorr==k){
                    count++;
                }
            }

        }return count;
    }

int subarraysWithXorK(vector<int> &nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        int count=0;
        int xorr=0;
        mpp[xorr]++;//initial as (0,1)
        for(int i=0;i<n;i++){
            xorr^=nums[i];
            int x=xorr^k;//derived formula from algo and intuition
            count+=mpp[x];
            mpp[xorr]++;
            
        }return count;
    }

int main(){

    return 0;
}