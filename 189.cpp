#include <iostream>
#include <algorithm>

using namespace std;
void rotate(vector<int>& nums, int k){
  int n=nums.size();
  if (n == 0)
    return;
  k = k % n;
  if (k > n) 
    return;
  vector<int> temp(k);
  for (int i = n - k; i < n; i++)
  {
    temp[i - n + k] = nums[i];
  }
  for (int i = n - k - 1; i >= 0; i--)
  {
    nums[i + k] = nums[i];
  }
  for (int i = 0; i < k; i++)
  {
    nums[i] = temp[i];
  }
}

void rotate2(vector<int>& nums, int k){
    int n=nums.size();
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin()+k, nums.begin() + n);
    reverse(nums.begin(), nums.begin() + n);

}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int k;
    cin>>k;
    rotate(nums,k);
    cout<<endl;


    return 0;
}
