#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int maxSubArray2(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    int sum=0;
    for(int i = 0; i < n; i++) {
        
        sum += nums[i];
        maxSum = max(maxSum, sum); // negatve could be also stored
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
