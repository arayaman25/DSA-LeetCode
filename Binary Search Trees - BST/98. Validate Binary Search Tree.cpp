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

// TC : O(N) 
//SC: O(1)
class Solution {
public:
    bool check(TreeNode* root, long long mini, long long maxi) {
        if (root == NULL) return true;

        if (root->val <= mini || root->val >= maxi) return false;
        return check(root->left, mini, root->val) && check(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};


 // TC : O(N) 
//SC: O(1)
//Morris Traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = NULL;

        while(curr != NULL){
            if(curr -> left == NULL){
                if (prev != nullptr && prev->val >= curr->val) return false;

                prev = curr;
                curr = curr -> right;
            }
            else{
                TreeNode* leftChild = curr -> left;
                while(leftChild -> right != NULL) leftChild = leftChild -> right;

                leftChild -> right = curr;
                TreeNode* temp = curr;
                curr = curr -> left;
                temp -> left = NULL;
            }
        }
        return true;
    }
};


