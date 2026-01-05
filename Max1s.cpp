#include <iostream>
using namespace std;
  int LowerBound(vector<int>& arr,int n,int x){
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
    return ans;
  }
  int rowWithMax1s(vector < vector < int >> & mat) {
    int n=mat.size();
    int m=mat[0].size();
    int maxCount=0,index=-1;
    for(int i=0;i<n;i++){
      int count=m - LowerBound(mat[i],m,1); // 1s = total - index of first 1
      if(count>maxCount){
        maxCount=count;
        index=i;
      }
    }
    return index;
  }