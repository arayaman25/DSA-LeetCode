
#include<iostream>
using namespace std;
double Brute_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int k=max(m,n);
        vector<int> ans;
        for(int i=0;i<(m+n);i++){
            if(i<m) ans.push_back(nums1[i]);
            if(i<n) ans.push_back(nums2[i]);
        }
        sort(ans.begin(),ans.end());
        int n2=ans.size();
        if(n2%2!=0) return (double) ans[n2/2];
        else {
            int n3=n2/2;
            double sum=(ans[n3]+ans[n3-1])/2.0;
            return sum;
        }
        return -1;
    }

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { //BS
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1); //ensure that the first array is smallest
        int low=0,high=min(n1,n2);
        int n=n1+n2;
        int left=(n1+n2+1)/2;
        while(low<=high){
            int mid1=low + (high-low)/2;
            int mid2=left-mid1;
            int l1=INT_MIN , l2=INT_MIN , r1=INT_MAX , r2=INT_MAX;
            if(mid1<n1) r1=nums1[(mid1)];
            if(mid2<n2) r2=nums2[(mid2)];
            if(mid1-1>=0) l1=nums1[(mid1-1)];
            if(mid2-1>=0) l2=nums2[(mid2-1)]; 
            if(l1<=r2 && l2<=r1){
                if(n%2==1) return (double) max(l1,l2);
                else return (double) (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) high=mid1-1;
            else  low=mid1+1; //(l2>r1)
        }
        return 0;
    }    