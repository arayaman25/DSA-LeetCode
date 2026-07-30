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
  

// TC : O(N^2) SC: O(N)

  class Solution {
public:
    int maxDiameter = 0;
    int maxDepth(TreeNode* root) {
            if(root == NULL) return 0;
            int lh = maxDepth(root -> left);
            int rh = maxDepth(root -> right);

            return 1 + max(lh, rh);
        }

    int diameterOfBinaryTree(TreeNode* root) {
        TreeNode* node = root; 
        if(node == NULL) return 0;

        int lh = maxDepth(node -> left);
        int rh = maxDepth(node -> right);

        maxDiameter = max(maxDiameter, lh+rh);

        diameterOfBinaryTree(root -> left);
        diameterOfBinaryTree(root -> right);

        return maxDiameter ;
    }
};


// TC : O(N) SC: O(N)

class Solution {
public:
    int maxDiameter = 0;

    int height(TreeNode* root, int &maxDiameter) {
            if(root == NULL) return 0;
            int lh = height(root -> left, maxDiameter);
            int rh = height(root -> right, maxDiameter);
            maxDiameter = max(maxDiameter, lh + rh);

            return 1 + max(lh, rh);
        }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        height(root, maxDiameter);

        return maxDiameter ;
    }
};