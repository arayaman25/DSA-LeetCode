#include <iostream>
using namespace std;
int singleNumber(vector<int>& nums) {
    int XOR=0;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        XOR^=nums[i];
    }
    return XOR;

}

int singleNumber(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[i] == nums[j]) 
              count++;
        }
        if (count == 1) 
          return nums[i];
    }
    return -1; //if not found 
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }


    return 0;
}
