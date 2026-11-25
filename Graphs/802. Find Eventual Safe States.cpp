#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> graphRev(n);
        vector<int> inDeg(n, 0);
        for(int i = 0 ; i < n ; i++){
            for(auto it : graph[i]){
                graphRev[it].push_back(i);
                inDeg[i]++;
            }
        }
        queue<int> q;
        for(int i = 0. ; i < n ; i++){
            if(inDeg[i] == 0) q.push(i);
        }

        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it : graphRev[node]){
                inDeg[it]--;
                if(inDeg[it] == 0) q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};