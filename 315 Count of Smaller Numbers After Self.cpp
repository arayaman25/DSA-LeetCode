#include <iostream>
#include <vector>
using namespace std;

vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n,0);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] > nums[j]){
                    count[i]++;
                }
            }
        }
       return count;
   
    }
int main(){

    return 0;


}