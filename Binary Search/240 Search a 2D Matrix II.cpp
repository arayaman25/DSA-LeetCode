#include<iostream>
using namespace std;
// Brute n X log m
    bool LowerBound(vector<int>& arr,int n,int x){
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
      int mid=low+(high-low)/2;
      if(arr[mid]>=x){
        ans=mid;
        high=mid-1;
      }
      else low=mid+1;
    }
    if (ans == n) return false;             
    return arr[ans] == x;
  }
    bool Brute_searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(LowerBound(matrix[i],m,target)) return true;
      }
      return false;
      
    }
// Optimal m+n
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0,col=m-1;
        while(row<n && col>=0){
            int val=matrix[row][col];
            if(val==target) return true;
            else if(val>target) col--;
            else row++;
        }
        return false;
        
    }