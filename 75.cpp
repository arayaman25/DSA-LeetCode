#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


void sortColors1(vector<int>& nums) {
    int n=nums.size();
    int c1=0,c2=0,c3=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            c1++;
        }
        else if(nums[i]==1){
            c2++;
        }
        else{
            c3++;
        }
    }
    for(int i=1;i<=n;i++){
        if(i<=c1){
            nums[i-1]=0;
        }
        else if(i<=c1+c2 && i>c1){
            nums[i-1]=1;
            
        }
        else{
            nums[i-1]=2;
        }
    }

    
}

void sortColors2(vector<int>& nums) {
    int n=nums.size();
    vector<int> hash(3, 0);
    for(int i=0;i<n;i++){
       hash[nums[i]]++;
    }
    int k=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<hash[i];j++){
            nums[k]=i;
            k++;
        }
       
    }  
}

void sortColors3(vector<int>& nums) { // Dutch NAtional flag method
   int n=nums.size();
   int mid=0,low=0,high=n-1;
   while(mid<=high){
    if(nums[mid]==0){
        swap(nums[low],nums[mid]);
        low++;
        mid++;
    }
    else if(nums[mid]==1){
        mid++;
    }
    else{
        swap(nums[high],nums[mid]);
        high--;
    }
}

}

int main() {
    int x;
    cin>>x;

    cout << "Hey. " << x;

    return 0;
}
