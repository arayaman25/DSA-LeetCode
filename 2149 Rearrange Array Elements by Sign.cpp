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


vector<int> rearrangeArray(vector<int>& nums){
   int nn=nums.size();
    vector<int> ans(nn);
    int p=0,n=1;
    for(int x : nums){
        if(x > 0){
            ans[p]=x;
            p+=2;
        }
        else {
            ans[n]=x;
            n+=2;
        }
    }
    
    return ans;
}

vector<int> rearrangeArray2(vector<int>& nums){
  
  int n=nums.size();
  

}


int main() {
    int x;
    cin>>x;

    cout << "Hey. " << x;

    return 0;
}
