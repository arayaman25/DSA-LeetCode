#include <iostream>
using namespace std;


class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int res = 1;
        while(res <= n) res = res << 1;  // res * 2

        return res;

    }
};