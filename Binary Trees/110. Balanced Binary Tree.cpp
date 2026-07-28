#include<iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

//TC : O(N^2) 
class Solution {
public:
    int depth(TreeNode* node){
        if(node == NULL) return 0;

        int lh = depth(node -> left);
        int rh = depth(node -> right);

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int lh = depth(root -> left);
        int rh = depth(root -> right);

        if(abs(lh-rh) > 1) return false;

        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);

        if(!left || !right) return false;

        return true;
    }
};