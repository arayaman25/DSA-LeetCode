#include <iostream>
using namespace std;

// TC: O(n² + 2048 × n) ≈ O(n²)     SC: O(2048)

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool> pairXor(2048, false);
        vector<bool> tripletXor(2048, false);

        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }

        for(int i = 0; i < 2048; i++){
            if (!pairXor[i]) continue;

            for(int j = 0; j < n ; j++){
                tripletXor[i ^ nums[j]] = true;
            }
        }  


        int ans = 0;
        for (bool exists : tripletXor) {
            if (exists) ans++;
        }

        return ans;
    }
};