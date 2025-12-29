// Standard I/O
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

void nextPermutation(vector<int>& nums){
    next_permutation(nums.begin(),nums.end()); // c++ exclusive
}

vector<int> nextPermutation2(vector<int>& nums) { //brute
        // Store all permutations
        vector<vector<int>> all;

        // Generate all permutations
        sort(nums.begin(), nums.end());
        do {
            all.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        // Traverse the list to find current permutation
        for (int i = 0; i < all.size(); i++) {
            if (all[i] == nums) {
                // If it's the last permutation
                if (i == all.size() - 1)
                    return all[0];
                // Return the next one
                return all[i + 1];
            }
        }

        // Return original if not found (shouldn't happen)
        return nums;
    }

void nextPermutation(vector<int>& nums) { //optimal
    int n = nums.size();
    int ind = -1;

    // Step 1: Find the pivot
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            ind = i;
            break;
        }
    }

    // Step 2: If no pivot, reverse entire array
    if (ind == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find the smallest element > nums[ind] from the right
    for (int i = n - 1; i > ind; i--) {
        if (nums[i] > nums[ind]) {
            swap(nums[i], nums[ind]);
            break;
        }
    }

    // Step 4: Reverse the right side
    reverse(nums.begin() + ind + 1, nums.end());
}


int main() {
    int x;
    cin>>x;

    cout << "Hey. " << x;

    return 0;
}
