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


// TC: O(H)
// SC: O(1)
class Solution {
public:

    TreeNode* changeLinks(TreeNode* root){
        if(root -> left == NULL) return root -> right;
        else if(root -> right == NULL) return root -> left;

        TreeNode* rightChild = root -> right;
        TreeNode* lastRight = findLastRight(root -> left);
        lastRight -> right = rightChild;
        return root -> left;

    }

    TreeNode* findLastRight(TreeNode* root) {
        while (root->right != NULL) root = root->right;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root -> val == key) return changeLinks(root);
        TreeNode* ogRoot = root;
        while(root != NULL){
            if(root -> val > key){
                if(root -> left != NULL && root -> left -> val == key){
                    root -> left = changeLinks(root -> left);
                    break;
                }
                else root = root -> left;
            }
            else{
                if(root -> right != NULL && root -> right -> val == key){
                    root -> right = changeLinks(root -> right);
                    break;
                }
                else root = root -> right;
            }
        }
        return ogRoot;
    }
};