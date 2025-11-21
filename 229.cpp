#include <iostream>
#include <vector>
#include <map>
using namespace std;

    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second>n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
    int count1=0;
    int count2=0;
    int ele1=INT_MIN;
    int ele2=INT_MIN;
   for(int i=0;i<n;i++){
    if(count1==0 && nums[i]!=ele2){
        count1=1;
        ele1=nums[i];
    } 
    else if(count2==0 && nums[i]!=ele1){
        count2=1;
        ele2=nums[i];
    } 
    else if(nums[i]==ele1){
        count1++;
    }
    else if(nums[i]==ele2){
        count2++;
    }

    else{
        count1--;
        count2--;

    }
   }
   int c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==ele1) c1++;
        if(nums[i]==ele2) c2++;

    }
    if(c1>n/3) ans.push_back(ele1);
    if(c2>n/3) ans.push_back(ele2);


    return ans;
    }
    
    int main(){
        return 0;
    }