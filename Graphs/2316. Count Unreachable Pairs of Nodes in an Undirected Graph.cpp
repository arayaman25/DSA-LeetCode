#include <iostream>
using namespace std;

//DFS
class Solution {
public:

    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, int& count){
        visited[u] = true;
        for(int& v : adj[u]){
            if(visited[v]) continue;
            else{
                count++;
                dfs(v, adj, visited, count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int rem = n;
        long long ans = 0;
        for(int u = 0; u < n ; u++){
            if(!visited[u]){
                int count = 1;
                dfs(u, adj, visited, count);
                ans += 1LL * count * (rem - count);
                rem = rem - count;    
            }
        }
        return ans;
    }
};
//<--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

//DSU
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]); 
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[y_parent] > rank[x_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }

    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n ; i++) parent[i] = i;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            Union(u, v);
        }

        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            int daddy = find(i);
            mp[daddy]++;
        }

        long long ans = 0;
        long long rem = n;

        for(auto &it : mp){
            long long count = it.second;
            ans += count * (rem - count);
            rem -= count;
        }
        return ans;
    }    
};