#include <iostream>
using namespace std;
bool check(vector<int>& nums) {
    int count=0;
    if (nums.back() > nums.front()) 
    {
     count++;
    } 

    for(int i=0;i<nums.size()-1;i++)
    {
       if(nums[i]>nums[i+1])
       {
        count++;
       }

    }
    if(count<=1)
    {
        return true;
    }
    else
    {
        return false;
    }

}


int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    bool v = check(nums);  
    cout<<v;

    return 0;
}
