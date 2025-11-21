#// Standard I/O
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>

// Containers
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <forward_list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>

// Strings & text
#include <string>
#include <cstring>
#include <string_view>

// Algorithms & utilities
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <optional>
#include <variant>
#include <tuple>
#include <limits>
#include <bitset>
#include <initializer_list>

// Math
#include <cmath>
#include <complex>
#include <random>


using namespace std;

vector<int> leaders(vector<int>& nums){
    int n= nums.size();
    vector<int> ans;
        int maxRight = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > maxRight) {
                ans.push_back(nums[i]);
                maxRight = nums[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
}

int main() {
    int x;
    cin>>x;

    cout << "Hey. " << x;

    return 0;
}
