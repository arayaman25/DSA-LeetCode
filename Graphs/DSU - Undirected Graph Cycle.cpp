#include <iostream>
using namespace std;

//TC: O(E α(V)), effectively almost O(E)
//SC: O(V)

class Solution {
  public:
  
  vector<int> parent;
  vector<int> rank;
  
  int find(int x){
      if(x == parent[x]) return x;
      return parent[x] = find(parent[x]);
  }
  
  void Union(int x, int y){
      int x_parent = find(x);
      int y_parent = find(y);
      
      if(x_parent == y_parent ) return;
      
      if(rank[x_parent] > rank[y_parent]) parent[y_parent] = x_parent;
      else if(rank[y_parent] > rank[x_parent]) parent[x_parent] = y_parent;
      else{
          parent[x_parent] = y_parent;
          rank[y_parent]++;
      }
  }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
       // Build adjacency list
          vector<vector<int>> adj(V);
          for (auto &edge : edges) {

              int u = edge[0];
              int v = edge[1];

              adj[u].push_back(v);
              adj[v].push_back(u);
          }
          
          parent.resize(V);
          rank.resize(V);
          
          for(int i = 0; i < V ; i++){
              parent[i] = i;
              rank[i] = 1;
          }
          
          for(int u = 0; u < V ; u++){
              for(int &v : adj[u]){
                  
                  if(u == v) return true;   // self-loop
                  
                  if(u < v){
                      int parent_u = find(u);
                      int parent_v = find(v);
                      
                      if(parent_u == parent_v) return true;
                      
                      Union(u, v);
                  }
              }
          }
          return false;
          
          
        
    }
};