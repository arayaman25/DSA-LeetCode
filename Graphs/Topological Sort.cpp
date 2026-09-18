#include <iostream>
using namespace std;

//DFS
//TC:O(V + E)
//SC:O(V + E)


class Solution {
  public:
  void topDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st) {

     visited[u] = true;

     for(int& v : adj[u]){
         if(!visited[v]){
             topDFS(adj, v, visited, st);
         }
     }
     st.push(u);
  }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }
        
        stack<int> st;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
        
            if (!visited[i]) {
                topDFS(adj, i, visited, st);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans; 
    }
};