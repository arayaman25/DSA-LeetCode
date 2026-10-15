#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<pair<int, int>>> adj(V + 1);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<
            pair<long long, long long>,
            vector<pair<long long, long long>>,
            greater<pair<long long, long long>>
        > pq;

        vector<long long> result(V + 1, LLONG_MAX);

        result[dest] = 0;
        pq.push({0, dest});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > result[node]) continue;

            for (auto &vec : adj[node]) {
                int adjNode = vec.first;
                int wt = vec.second;

                if (d + wt < result[adjNode]) {
                    result[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }

        if (result[src] == LLONG_MAX) return {-1};

        vector<int> path;
        int node = src;

        path.push_back(src);

        while (node != dest) {
            int nextNode = INT_MAX;

            for (auto &vec : adj[node]) {
                int adjNode = vec.first;
                int wt = vec.second;

                if (result[adjNode] != LLONG_MAX && result[node] == result[adjNode] + wt) {
                    nextNode = min(nextNode, adjNode);
                }
            }

            path.push_back(nextNode);
            node = nextNode;
        }

        return path;
    }
};