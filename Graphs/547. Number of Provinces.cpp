#include <iostream>
using namespace std;

//DFS APPROACH

class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& isConnected, int u, vector<bool>& visited){
        visited[u] = true;

        for(int v = 0; v < n; v++){
            if(!visited[v] && isConnected[u][v] == 1){
                dfs(isConnected, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(isConnected, i, visited);
            }
        }
        return count;
    }
};


//BFS APPROACH
class Solution {
public:

    void bfs(vector<vector<int>>& isConnected, vector<int>& vis, int start) {
        int n = isConnected.size();

        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int v = 0; v < n; v++) {
                if (isConnected[node][v] == 1 && !vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                bfs(isConnected, vis, i);
            }
        }

        return cnt;
    }
};