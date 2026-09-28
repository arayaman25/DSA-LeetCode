#include <iostream>
using namespace std;

//BFS
//TC : O(V + E)
//SC : O(V)
class Solution {
public:

    bool checkBipartiteBFS(vector<vector<int>>& graph, int curr,vector<int> &color, int currColor ){
        queue<int> que;
        que.push(curr);
        color[curr] = currColor;

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int &v : graph[u]){
                if(color[v] == color[curr]) return false;
                if(color[v] == -1){
                    color[v] = 1 - color[curr];
                    if(checkBipartiteBFS(graph, v, color, color[v]) == false) return false;
                }
            }
        }
        return true;
    }    

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int i = 0 ; i < V ; i++){
            if(color[i] == -1){
                if(checkBipartiteBFS(graph, i, color, 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};