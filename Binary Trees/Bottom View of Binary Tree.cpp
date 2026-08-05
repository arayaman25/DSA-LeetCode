#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Time: O(n log n) (n BFS visits + log n map operations)
// Space: O(n) (queue + map)
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        map<int,int> mp;
        if(root == NULL) return ans;
        
        queue<pair<Node*,int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node *node = p.first;
            int vLevel = p.second;
            mp[vLevel] = node -> data;
            
            if(node -> left) q.push({node -> left, vLevel - 1 });
            if(node -> right) q.push({node -> right, vLevel + 1 });
        
        }
        for (auto it : mp)  ans.push_back(it.second);
        
        return ans;
    }
};