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

void rotate(vector<vector<int>>& matrix) { //brute 
    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }

    matrix = ans;
}
        
void rotate2(vector<vector<int>>& matrix) { //optimmal 
    int n = matrix.size();

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
     for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
     }

}
        

int main() {
    int x;
    cin>>x;

    cout << "Hey. " << x;

    return 0;
}
