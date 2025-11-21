#include <iostream>
#include <vector>
using namespace std;

// vector<int> getConcatenation(vector<int>&nums)
// {
//     vector<int> num2=nums;
//     int k=0;
//     for(int i=0;i<nums.size();i++)
//     {
//        num2.push_back(nums[i]);
//     }
//     return num2;
// }
vector<int> getConcatenation(vector<int>& nums)
{
    vector<int> num2(2 * nums.size());  
    for (int i = 0; i < nums.size(); i++) 
    {
        num2[i] = nums[i];              
        num2[i + nums.size()] = nums[i]; 
    }
    return num2;
}


int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int> v = getConcatenation(nums);  
    for (int i : v) 
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
