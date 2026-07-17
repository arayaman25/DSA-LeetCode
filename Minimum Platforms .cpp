#include <iostream>
using namespace std;

//TC : O 2(N + NlogN) SC: O(1)
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(),  arr.end());
        sort(dep.begin(),  dep.end());
        
        int i = 0 ,  j = 0;
        int count = 0 , maxCount=0;
        while(i < n){
        
            if(arr[i] <= dep[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            maxCount = max(maxCount , count);
        }
        return maxCount;
        
        
        
        
    }
};
