#include <iostream>
#include <vector>
#include <map>

using namespace std;

int majorityElement(vector<int>& nums){
    int n=nums.size();
    for(int i =0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }
        if (count>n/2){
            return nums[i];
        }

    }
    return -1;
}

int majorityElement2(vector<int>& nums){
    int n=nums.size();
    map <int,int> mpp;
    for(int i =0;i<n;i++){
        mpp[nums[i]]++;
        
    }
    for(auto it: mpp){
        if(it.second > n/2){
            return it.first;
        }
    }
    return -1;
}

int majorityElement2(vector<int>& nums){
    int n=nums.size();
    int count=0;
    int ele;
   for(int i=0;i<n;i++){
    if(count==0){
        count=1;
        ele=nums[i];
    } 
    else if(nums[i]==ele){
        count++;
    }
    else{
        count--;
    }
   }
   int count2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==ele){
            count2++;
        }
    }
    if(count2>n/2){
        return ele;
    }

    return -1;  
}



int main() {
    int x;
    cin>>x;

    cout << "Hey. " << x;

    return -1;
}
