#include <iostream>
#include <vector>
using namespace std;

 long long numberOfInversions(vector<int>& nums){
        int n = nums.size();
        long long count = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] > nums[j]){
                    count++;
                }
            }
        }

        return count;
    }

int main(){
    vector<int> v={5,3,2,4,1};
    cout<<numberOfInversions(v)<<endl;
    return 0;


}