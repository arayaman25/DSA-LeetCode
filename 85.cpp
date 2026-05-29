#include<iostream>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        long long maxArea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()? -1 : st.top();
                long long area=heights[element]*(nse-pse-1);
                maxArea=max(maxArea,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int element=st.top();
            st.pop();
            int nse=n;
            int pse=st.empty()? -1 : st.top();
            long long area=heights[element]*(nse-pse-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        if(matrix.empty()) return 0;
        vector<vector<int>> pmat(rows, vector<int>(cols, 0));
        for(int i=0;i<cols;i++){
            int sum=0;
            for(int j=0;j<rows;j++){
                sum+=matrix[j][i]-'0';
                if(matrix[j][i]=='0') sum=0;
                pmat[j][i]=sum;
            }
        }
        long long maxArea=0;
        for(int i=0;i<rows;i++){
           long long area=largestRectangleArea(pmat[i]);
           maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};