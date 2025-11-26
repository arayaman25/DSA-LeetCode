#include <iostream>
#include <vector>

using namespace std;
int reversePairs(vector<int>& nums) {
        long long n=nums.size();
        long long count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((long long)nums[i]>2*(long long)nums[j]) count++;
            }
        }
        return count;
    }
    int main(){
        return 0;
    }