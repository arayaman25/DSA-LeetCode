#include <iostream>
using namespace std;

//TC : O(M x N)
//SC : O(M x N)
class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited, int m, int n){
        visited[row][col] = true;
        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        for(int i = 0 ; i < 4 ; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow >= 0 && newRow < m &&
               newCol >= 0 && newCol < n &&
               grid[newRow][newCol] == '1' && !visited[newRow][newCol]){
                    dfs(newRow, newCol, grid, visited, m , n);
               }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    dfs(i, j , grid, visited, m, n);
                }
            }
        }
        return count;
    }
};