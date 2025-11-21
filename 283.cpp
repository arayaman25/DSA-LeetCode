#include <iostream>
#include <algorithm>

using namespace std;
void moveZeroes(vector<int>& nums) {
    int n=nums.size();
    int j=0;
    for(int i=0;i<n;i++)
    {
        if (nums[i]!=0){
            if(i!=j){
              nums[j]=nums[i];
            }
            j++;
        }
    }
    for(int i=j;i<n;i++)
    {
        
            nums[i]=0;
    }
    
    for (int i : nums) 
    {
        cout << i << " ";
    }
    cout << endl;
}
void moveZeroes2(vector<int>& nums) {
    int n=nums.size();
    int j=-1;
    for(int i=0;i<n;i++) //finding the first zero index
    {
        if(nums[i]==0)
        {
            j=i;
            break;
        }

    }
    if (j == -1) return;
    for(int i=j+1;i<n;i++) 
    {
        if(nums[i]!=0)
        {
            swap(nums[j],nums[i]);
            j++;
        }

    }

    for (int i : nums) 
    {
        cout << i << " ";
    }
    cout << endl;


}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    moveZeroes(nums);

    return 0;
}
