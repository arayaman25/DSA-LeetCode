#include<iostream>
using namespace std;

//brute
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        long long maxArea=0;
        int r=0,l=0;
        for(int i=0;i<n;i++){
            r=i;
            l=i;
            for(int j=i+1;j<n;j++){
                if(heights[j]<heights[i]){
                    r=j-1;
                    break;
                }
                r=j;
            }
            for(int j=i-1;j>=0;j--){
                if(heights[j]<heights[i]){
                    l=j+1;
                    break;
                }
                l=j;
            }
            long long area=heights[i]*(r-l+1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};

//--------------------------------------------------


//better
class Solution {
public:
    vector<int> nse(vector<int> nums){
        int n=nums.size();
        stack<int>st;
        vector<int> nse(n);
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
        stack<int>st;
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();

            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();

            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        long long maxArea=0;
        vector<int> nsee=nse(heights);
        vector<int> psee=pse(heights);

        for(int i=0;i<n;i++){

            int width = nsee[i] - psee[i] - 1;

            long long area=heights[i]*width;
            maxArea=max(maxArea,area);


        }
        return maxArea;
    }
};

//--------------------------------------------------