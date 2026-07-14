#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int req = target - num;
        if (mpp.find(req) != mpp.end()) {
            return {mpp[req], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}


int main() 
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int target;
    cin>>target;


    return 0;
}
