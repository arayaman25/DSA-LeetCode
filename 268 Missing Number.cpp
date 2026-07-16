#include <iostream>
#include <vector>
using namespace std;
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int x : nums){
         sum += x;
    }     
    return total - sum;
}
int missingNumber2(vector<int>& nums) { //XOR method
    int n = nums.size();
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n; i++) {
        xor1 ^= nums[i];
        xor2 ^= (i + 1);
    }

    return xor1 ^ xor2;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout <<missingNumber(nums)<<endl;

    return 0;
}
