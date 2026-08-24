#include<iostream>
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
  

// TC : O(N) SC: O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int z = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size, 0);
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);

                int ind = (z % 2) ? size - i -1 : i ;
                level[ind] = node -> val;
            }
    
            
            ans.push_back(level);
            z++;
        }
        return ans;
    }
};