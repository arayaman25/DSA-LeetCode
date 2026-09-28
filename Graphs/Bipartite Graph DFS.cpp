#include <iostream>
using namespace std;
class Solution {
  public:
  
  bool checkBipartiteDFS(unordered_map<int, vector<int>>& adj, int curr,vector<int> &color, int currColor ){
    color[curr] = currColor;
    for(int &v : adj[curr]){
        if(color[v] == color[curr]) return false;
        if(color[v] == -1){
            color[v] = 1 - color[curr];
            if(checkBipartiteDFS(adj, v, color, color[v]) == false){
                return false;
            }
        }
    }
    return true;
  }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        unordered_map<int, vector<int>> adj;
        vector<int> color(V, -1);
        for(auto &vec : edges){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            adj[a].push_back(b);
        }
        
        for(int i = 0 ; i < V ; i++){
            if(color[i] == -1){
                if(checkBipartiteDFS(adj, i , color, 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};