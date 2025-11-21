#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target){
    int n=nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k= j+1;k<n;k++){
                int sum=0;
                for(int l=k+1;l<n;l++){
                    sum=nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        
    }
    return vector<vector<int>> (st.begin(),st.end());
}

vector<vector<int>> fourSum2(vector<int>& nums, int target) {
   int n = nums.size();
        set<vector<int>> st;  

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<int> seen;
                for (int k = j + 1; k < n; k++) {
                    long long required = (long long)target - nums[i] - nums[j] - nums[k];
                    if (seen.count(required)) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)required};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }


                    seen.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());

}

vector<vector<int>> fourSum3(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] +
                                    nums[left] + nums[right];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j],nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;

                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }
        return ans;
    }

int main(){
    return 0;
}