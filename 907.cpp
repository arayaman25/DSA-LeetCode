#include<iostream>
using namespace std;

//brute
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            int mini = nums[i];
            int maxi = nums[i];

            for(int j = i; j < n; j++) {

                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);

                sum += (maxi - mini);
            }
        }

        return sum;
    }
};

//optimal
class Solution {
public:
    vector<int> nse(vector<int> nums){
        int n=nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();

            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();

            st.push(i);
        }
        return nse;
    }
    vector<int> pse(vector<int> nums){
        int n=nums.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();

            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            
            st.push(i);
        }
        return pse;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nsee=nse(arr);
        vector<int> psee=pse(arr);
        long long total = 0;
        for(int i=0;i<n;i++){
            long long left=i-psee[i];
            long long right=nsee[i]-i;
            total = (total + (right * left * 1LL * arr[i]));
        }
        return total;

    }


    vector<int> nge(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i =n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if(st.empty()) nge[i] = n;
            else nge[i] = st.top();

            st.push(i);
        }
        return nge;
    }

    vector<int> pge(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i = 0; i <n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();

            st.push(i);
        }
        return nge;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        vector<int> ngee=nge(arr);
        vector<int> pgee=pge(arr);
        long long total = 0;
        for(int i=0;i<n;i++){
            long long left=i-pgee[i];
            long long right=ngee[i]-i;
            total = (total + (right * left * 1LL * arr[i]));
        }
        return total;

    }


    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};85