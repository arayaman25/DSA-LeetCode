#include <iostream>
using namespace std;

//DFS
//TC:O(V + E)
//SC:O(V + E)
class Solution {
public:

    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {

       visited[u] = true;
       inRecursion[u] = true;
       
       for(int& v : adj[u]){
           if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion)){
               return true;
           }
           else if(inRecursion[v] == true){
               return true;
           }
       }
       inRecursion[u] = false;

        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {

        // Build adjacency list
        vector<vector<int>> adj(V);

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);

        // Handle disconnected graph
        for (int i = 0; i < V; i++) {

            if (!visited[i]) {

                if (isCycleDFS(adj, i, visited, inRecursion))
                    return true;
            }
        }

        return false;
    }
};