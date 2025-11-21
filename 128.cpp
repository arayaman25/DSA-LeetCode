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

int longestConsecutive(vector<int>& nums){//better
    if (nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());
    int MaxCount=1;
    int count=1;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i+1]-nums[i]==1){
            count++;
        }
        else if(nums[i+1]==nums[i]){
            continue;
        }
        else{
            MaxCount=max(MaxCount,count);
            count=1;
        }
    } 
    MaxCount = max(MaxCount, count);
    return MaxCount;  
}

int main() {
    int x;
    cin>>x;

    cout << "Hey. " << x;

    return 0;
}
