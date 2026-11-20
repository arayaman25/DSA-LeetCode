#include <iostream>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q; // {{r, c}, t}
        int visited[n][m];
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else visited[i][j] = 0;
            }
        }

        int time = 0;
        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
            int newRow = r + delRow[i];
            int newCol = c + delCol[i];

            if(newRow >= 0 && newRow < n &&
               newCol >= 0 && newCol < m &&
               grid[newRow][newCol] == 1 && !visited[newRow][newCol]){
                    q.push({{newRow, newCol}, t + 1});
                    visited[newRow][newCol] = 2;
               }
            }

        }

        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 1 && visited[i][j] != 2) return -1;
            }
        }


        return time;
        
    }
};