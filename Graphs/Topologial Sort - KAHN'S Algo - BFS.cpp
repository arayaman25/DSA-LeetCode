#include <iostream>
using namespace std;


// BFS — Kahn's Algorithm
//TC:O(V + E)
//SC:O(V + E)

class Solution {
  public:

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V); 

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }
        
        queue<int> que;    
       vector<int> inDeg(V, 0);
       for(int u = 0; u < V ; u++){
           for(int &v : adj[u]){
               inDeg[v]++;
           }
       }
       
       for(int i = 0 ; i < V ; i++){
           if(inDeg[i] == 0){
               que.push(i);
           }
       }
       
       vector<int> result;
       while(!que.empty()){
           int u = que.front();
           result.push_back(u);
           que.pop();
           
           for(int &v : adj[u]){
               inDeg[v]--;
               
               if(inDeg[v] == 0) que.push(v);
               
           }
           
       }
       return result;
    }
};