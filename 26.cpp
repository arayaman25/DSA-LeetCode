#include <iostream>
#include <set>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int j=0;
    for(int i=0;i<nums.size()-1;i++)
    {
        if(nums[i]!=nums[i+1])
        {
            nums[j]=nums[i];
            j++;
        }
    }
    nums[j]=nums.back();//includes last element
    return j+1;


}
int removeDuplicates2(vector<int>& nums) { // O(NlogN)
    set<int> st;
    for(int i=0;i<nums.size();i++)
    {
       st.insert(nums[i]);// stores unique element only
    }
    int j=0;
    for(auto it:st)
    {
        nums[j]=it;
        j++;
    }
    return j;


}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    int v = removeDuplicates2(nums);
    for(int i=0;i<v;i++)
    {
        cout<<nums[i]<<" ";
    }      

    return 0;
}
