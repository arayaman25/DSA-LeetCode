#include<iostream>
#include<unordered_set>
using namespace std;


  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  

// TC : O(N2) SC: O(N)
class Solution {
public:
    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(root == NULL) return;

        if(root -> left) parent[root -> left] = root;        
        findParent(root -> left, parent);

        if(root -> right) parent[root -> right] = root;
        findParent(root -> right, parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        findParent(root, parent);

        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int> visited;
        visited.insert(target -> val);
        while(!q.empty()){
            int size = q.size();
            
            if(k == 0) break;

            for(int i = 0 ; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left && !visited.count(node -> left -> val)){
                    q.push(node -> left);
                    visited.insert(node -> left -> val);
                }

                if(node -> right && !visited.count(node -> right -> val)){
                    q.push(node -> right);
                    visited.insert(node -> right -> val);
                }

                if(parent.count(node) && !visited.count(parent[node] -> val)){
                    q.push(parent[node]);
                    visited.insert(parent[node] -> val);
                }
            }
            k--;

        }

        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node -> val);
        }
        return ans;
    }
};