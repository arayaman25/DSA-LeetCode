#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    int n=nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum=0;
            for(int k=j+1;k<n;k++){
                sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                   vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(), temp.end());  // avoid duplicates
                    st.insert(temp);
                }
            

            }

        }
        
    } 
    return vector<vector<int>>(st.begin(), st.end());
}

vector<vector<int>> threeSum2(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            set<int> hashset;
            for (int j = i + 1; j < n; j++) {
                int third = -(nums[i] + nums[j]);

                if (hashset.find(third) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }

                hashset.insert(nums[j]);
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }

vector<vector<int>> threeSum3(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++, right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
                else if (sum < 0) left++;
                else right--;
            }
        }
        return ans;
    }

    
int main(){
    return 0;
}