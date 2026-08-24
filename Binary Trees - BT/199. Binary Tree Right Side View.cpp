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


  //Iterative - level order
//Time: O(N)
//Space: O(N) (queue in the worst case)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i = 0 ; i < size ; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
                
                if(i == size - 1) ans.push_back(node -> val);
            }
        }
        return ans;
    }
};

// recursive 
class Solution {
public:
    void solve(TreeNode* root, int level, vector<int> &ans){
        if(root == NULL) return ;

        if(ans.size() == level) ans.push_back(root -> val);
        solve(root -> right, level + 1, ans);
        solve(root -> left, level + 1, ans); 
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};