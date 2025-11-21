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

void setZeroes(vector<vector<int>>& matrix){// better
            int m = matrix.size();
    int n = matrix[0].size();

    vector<pair<int,int>> zeros;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                zeros.push_back({i, j});
            }
        }
    }

    for(auto &p : zeros){
        int r = p.first;
        int c = p.second;
        for(int j = 0; j < n; j++){
            matrix[r][j] = 0;
        }
        for(int i = 0; i < m; i++){
            matrix[i][c] = 0;
        }
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    bool firstRow = false, firstCol = false;

    // Check first row
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            firstRow = true;
            break;
        }
    }

    // Check first column
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            firstCol = true;
            break;
        }
    }

    // Mark zeros using the first row and first column
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Apply markings to set inner matrix to zero
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero first row if needed
    if (firstRow) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Zero first column if needed
    if (firstCol) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}





int main() {
    int x;
    cin>>x;

    cout << "Hey. " << x;

    return 0;
}
