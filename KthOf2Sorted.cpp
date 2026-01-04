
#include<iostream>
using namespace std;
    int BrutekthElement(vector<int> &a, vector<int>& b, int k) {
   int n1 = a.size(), n2 = b.size();
    int n = n1 + n2;
    int  i = 0,cnt = 0, j = 0;
    int ele=-1;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            ele=a[i];
            i++;
        } else {
           ele=b[j];
            j++;
        }
        cnt++;
        if(cnt==k) return ele;
    }
    while (i < n1) {
        ele=a[i];
        cnt++;
        if(cnt==k) return ele;
        i++;
    }
    while (j < n2) {
        ele=b[j];
        cnt++;
        if(cnt==k) return ele;
        j++;
    }

    return -1;
    }

int kthElement(vector<int> &a, vector<int>& b, int k) {
       int m = a.size();
        int n = b.size();
        if (m > n) return kthElement(b, a, k); 
        int left = k; 
        int low = max(0, k - n), high = min(k, m);
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < m) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n) ? b[mid2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } 
            else if (l1 > r2) {
                high = mid1 - 1;
            } 
            else {
                low = mid1 + 1;
            }
        }
        return -1;
  }