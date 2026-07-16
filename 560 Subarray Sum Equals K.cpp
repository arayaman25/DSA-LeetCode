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

int subarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) count++;  // count subarrays, not track length
            }
        }
        return count;
    }

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    unordered_map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}


int main() {
    int x;
    cin>>x;

    cout << "Hey. " << x;

    return 0;
}
