#include <iostream>
using namespace std;

//TC : O( nlogn + nlogM ) SC: O(n)
class Solution {
public:


    int getGcd(int a , int b) {
        if(a > b){
            a = a + b;
            b = a - b;
            a = a - b;
        }

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int> prefixGcd;
        for(int i =0 ; i < n ; i++){
            maxi = max(maxi , nums[i]);
            prefixGcd.push_back(getGcd(nums[i], maxi));   
        }
        sort(prefixGcd.begin(), prefixGcd.end());

        int l = 0 , r = n-1;
        long long sum = 0;
        while(l < r){
            sum += getGcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        return sum;
        
    }
};