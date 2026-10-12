#include <iostream>
#include <set>
using namespace std;

//using pq
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int source) {

        vector<vector<pair<int, int>>> adj(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});  // Undirected graph
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> result(V, INT_MAX);

        result[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated distances 
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

        return result;
    }
};

//using set
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int source) {

        vector<vector<pair<int, int>>> adj(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});  // Undirected graph
        }

        set<pair<int, int>> st;

        vector<int> result(V, INT_MAX);

        result[source] = 0;
        st.insert({0, source});

        while (!st.empty()) {
            
            auto &it = *st.begin();
            int d = it.first;
            int node = it.second;
            st.erase(it);

            // Skip outdated distances
            if (d > result[node]) continue;

            for (auto &vec : adj[node]) {
                int adjNode = vec.first;
                int wt = vec.second;

                if (d + wt < result[adjNode]) {
                    
                    if(result[adjNode] != INT_MAX){
                        st.erase({result[adjNode], adjNode});
                    }
                    result[adjNode] = d + wt;
                    st.insert({d + wt, adjNode});
                }
            }
        }

        return result;
    }
};