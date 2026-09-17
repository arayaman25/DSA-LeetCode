#include <iostream>
using namespace std;

//DFS
//TC:O(V + E)
//SC:O(V + E)
class Solution {
public:
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, int parent) {
        visited[u] = true;

        for (int v : adj[u]) {

            if (v == parent)
                continue;

            if (visited[v])
                return true;

            if (isCycleDFS(adj, v, visited, u))
                return true;
        }

        return false;
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

        vector<bool> visited(V, false);

        // Handle disconnected graph
        for (int i = 0; i < V; i++) {

            if (!visited[i]) {

                if (isCycleDFS(adj, i, visited, -1))
                    return true;
            }
        }

        return false;
    }
};

//BFS
//TC:O(V + E)
//SC:O(V + E)
class Solution {
public:

    bool isCycleBFS(vector<vector<int>>& adj, int u, vector<bool>& visited) {

        queue<pair<int, int>> q;

        q.push({u, -1});
        visited[u] = true;

        while (!q.empty()) {

            pair<int, int> P = q.front();
            q.pop();

            int source = P.first;
            int parent = P.second;

            for (int &v : adj[source]) {

                if (visited[v] == false) {

                    visited[v] = true;
                    q.push({v, source});
                }
                else if (v != parent) {

                    return true;
                }
            }
        }

        return false;
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

        vector<bool> visited(V, false);

        // Handle disconnected graph
        for (int i = 0; i < V; i++) {

            if (!visited[i]) {

                if (isCycleBFS(adj, i, visited))
                    return true;
            }
        }

        return false;
    }
};