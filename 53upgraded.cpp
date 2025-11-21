#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
// printing th max subarray
int maxSubArray2(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    int sum=0;
    int start=0;
    int ansStart=-1,end=-1;
    for(int i = 0; i < n; i++) {
        if(sum==0){
            start =i;
        }
        sum += nums[i];
        if(sum>maxSum){
            maxSum=sum;
            ansStart=start;
            end=i;
        }
        if(sum<0){
            sum=0;
        }
        
    }

    return maxSum;
}

int main() {
    int x;
    cin>>x;

    cout << "Hey. " << x;

    return 0;
}
