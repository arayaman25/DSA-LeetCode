#include <iostream>
using namespace std;

class Solution {
public:
    bool topologicalSortCheck( unordered_map<int, vector<int>> adj, int n, vector<int> inDeg){
        queue<int> que;
        int count = 0;

        for(int i = 0; i < n ; i++){
            if(inDeg[i] == 0){
                count++;
                que.push(i);
            }
        }
        
        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int &v : adj[u]){
                inDeg[v]--;
                if(inDeg[v] == 0){
                    count++;
                    que.push(v);
                }
            }
        }
        
        if(count == n) return true;
        return false;
    }



    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDeg(numCourses, 0);

        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            inDeg[a]++;
        }
        return topologicalSortCheck(adj, numCourses, inDeg);
    }
};