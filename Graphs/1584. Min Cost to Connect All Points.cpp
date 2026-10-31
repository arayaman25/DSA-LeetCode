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


//using Kruskal
class Solution {
    typedef pair<int, int> P;
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
  
   int Kruskal(vector<vector<int>>& edges){
       int sum = 0;
       
       for(auto &temp : edges){
           int u = temp[0];
           int v = temp[1];
           int wt = temp[2];
           
           int parent_u = find(u);
           int parent_v = find(v);
           
           if(parent_u != parent_v){
               Union(u,v);
               sum += wt;
           }
           
       }
       return sum;
   }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        parent.resize(V);
        rank.resize(V, 0);
        
        for(int i = 0 ; i< V ; i++) parent[i] = i;

        int n = points.size();
        vector<vector<int>> vec;

        for(int i = 0 ; i < n ; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            for(int j = i + 1 ; j < n ; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1 - x2) + abs(y1 - y2);
                vec.push_back({i, j, d});
            }
        }
        
        auto comparator = [&](vector<int>& vec1, vector<int> & vec2){
            return vec1[2] < vec2[2];    
        };
        

        sort(vec.begin(), vec.end(), comparator);
        return Kruskal(vec);
        
    }
};