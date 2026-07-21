#include <iostream>
using namespace std;
    int Brute_findKthPositive(vector<int>& arr, int k) {
        int i=0,missCount=0,j=1;
        while(true){
            if(i<arr.size() && j==arr[i]){
                i++;
            }
            else {
                missCount++;
                if(missCount==k) return j;
            }    
            j++;
        }
        return -1;
        
    }
    int findKthPositive(vector<int>& arr, int k) {//optimal with binary search
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low + k;        
    }
