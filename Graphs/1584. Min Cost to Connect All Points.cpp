#include <iostream>
using namespace std;

//DFS
//TC: \(O(n^2 log n)
//SC:O(n^2)

class Solution {
    typedef pair<int, int> P;
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<P>> adj(n);

        for(int i = 0 ; i < n ; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            for(int j = i + 1 ; j < n ; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        vector<bool> inMST(n, false);
        int cost = 0;
        int count = 0;
        while(!pq.empty() && count < n){
            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;

            if(inMST[node]) continue;

            inMST[node] = true;
            cost += wt;
            count++;

            for(auto &temp : adj[node]){
                int neighbor = temp.first;
                int neighbor_wt = temp.second;

                if(!inMST[neighbor]){
                    pq.push({neighbor_wt, neighbor});
                }
            }
        }
        
        return cost;
        
    }
};