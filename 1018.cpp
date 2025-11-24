#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<bool> prefixesDivBy5(vector<int>& nums) {
        int prefix = 0;
        vector<bool> ans;
        
        for (int bit : nums) {
            prefix = (prefix * 2 + bit) % 5;
            ans.push_back(prefix == 0);
        }
        
        return ans;
    }
    int main(){
        return 0;
    }