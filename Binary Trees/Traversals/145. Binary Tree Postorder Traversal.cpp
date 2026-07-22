#include<iostream>
using namespace std;

// TC : O(N) SC: O(N)

  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  class Solution {
public:
    void postOrder(TreeNode* node, vector<int> &arr){
            if(node == NULL) return;

            postOrder(node -> left, arr);
            postOrder(node -> right, arr);
            arr.push_back(node -> val);
        }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};