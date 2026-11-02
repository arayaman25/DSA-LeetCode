#include <iostream>
using namespace std;

class Solution {
  public:
  
  void dfsFill(int u , vector<vector<int>>& adj, vector<bool>& visited, stack<int> &st){
      visited[u] = true;
      for(int &v : adj[u]){
          if(!visited[v]){
              dfsFill(v, adj, visited, st);
          }
      }
      st.push(u);
      
  }
  
  void dfsTraversal(int u , vector<vector<int>>& adjReversed, vector<bool>& visited){
      visited[u] = true;
      for(int &v : adjReversed[u]){
          if(!visited[v]){
              dfsTraversal(v, adjReversed, visited);
          }
      }
  }
  
    int countSCC(vector<vector<int>>& adj) {
        //Step 1 : sort in topo
        int V = adj.size();
        stack<int> st;
        vector<bool> visited(V, false);
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                dfsFill(i, adj, visited, st);
            }
        }
        
        //Step 2 Make a reversed graph
        vector<vector<int>> adjReversed(V);
        for(int u = 0; u < V ; u++){
            for(int &v : adj[u]){
                // make u -> v ko v -> u
                adjReversed[v].push_back(u);
            }
        }
        
        //Step 3 Call DFS based on stack order
        int countScc = 0;
        visited = vector<bool>(V, false);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                dfsTraversal(node, adjReversed, visited);
                countScc++;
            }
        }
        return countScc;
    }
};