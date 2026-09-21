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

//BFS - usinf KAHNS ALGO
//TC:O(V + E)
//SC:O(V + E)

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        // Build adjacency list
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        // Calculate indegree
        vector<int> inDeg(V, 0);

        for(int u = 0; u < V; u++) {
            for(int v : adj[u]) {
                inDeg[v]++;
            }
        }

        // Add all nodes with indegree 0
        queue<int> que;

        for(int i = 0; i < V; i++) {
            if(inDeg[i] == 0) {
                que.push(i);
            }
        }

        // Kahn's Algorithm
        int count = 0;

        while(!que.empty()) {

            int u = que.front();
            que.pop();

            count++;

            for(int v : adj[u]) {

                inDeg[v]--;

                if(inDeg[v] == 0) {
                    que.push(v);
                }
            }
        }

        // If not all vertices were processed, cycle exists
        if(count == V) return false; 
        return true;
    }
};