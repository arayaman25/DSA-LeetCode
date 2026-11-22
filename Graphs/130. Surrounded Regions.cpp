#include <iostream>
using namespace std;

class Solution {
public:
void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited, vector<pair<int,int>>& component, int m, int n, bool &boundary){
        visited[row][col] = true;

        component.push_back({row, col});
        if(row == 0 || row == m-1 || col == 0 || col == n-1) boundary = true;

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        for(int i = 0 ; i < 4 ; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow >= 0 && newRow < m &&
               newCol >= 0 && newCol < n &&
               board[newRow][newCol] == 'O' && !visited[newRow][newCol]){
                    dfs(newRow, newCol, board, visited, component, m , n, boundary);
               }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    bool boundary = false;
                    vector<pair<int,int>> component;

                    dfs(i, j , board, visited, component, m, n, boundary);
                    if(!boundary) {
                        for(auto it : component) {
                            board[it.first][it.second] = 'X';
                        }
                    }    
                }
            }
        }
    }
};