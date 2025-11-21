#include <iostream>
#include <vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int count = 0, maxCount = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1)
            count++;
        else {
            maxCount = max(maxCount, count);
            count = 0;
        }
    }
    return max(maxCount, count);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout <<findMaxConsecutiveOnes(nums)<<endl;

    return 0;
}
