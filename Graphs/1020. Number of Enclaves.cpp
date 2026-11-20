#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, int m, int n, int &count, bool &boundary){
        visited[row][col] = true;
        count++;

        if(row == 0 || row == m-1 || col == 0 || col == n-1) boundary = true;

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        for(int i = 0 ; i < 4 ; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow >= 0 && newRow < m &&
               newCol >= 0 && newCol < n &&
               grid[newRow][newCol] == 1 && !visited[newRow][newCol]){
                    dfs(newRow, newCol, grid, visited, m , n, count, boundary);
               }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    count = 0;
                    bool boundary = false;
                    dfs(i, j , grid, visited, m, n, count, boundary);
                    if(!boundary) ans += count;
                }
            }
        }
        return ans;
    }
};