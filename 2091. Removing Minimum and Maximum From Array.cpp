#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int maxi = 0;
        int mini = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[maxi]) maxi = i;
            if (nums[i] < nums[mini]) mini = i;
        }

        int left = max(maxi, mini) + 1;
        int right = n - min(maxi, mini);
        int mixed = (min(maxi, mini) + 1) + (n - max(maxi, mini));
        return min({left, right, mixed});
    }
};