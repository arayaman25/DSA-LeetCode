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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);

        TreeNode* temp = root;
        TreeNode* insert = new TreeNode(val);
        while(true){
            if(val > temp -> val){
                if(temp -> right == NULL){
                    temp -> right = insert;
                    return root;
                }
                temp = temp -> right;
            }

            else{
                if(temp -> left == NULL){
                    temp -> left = insert;
                    return root;
                }
                temp = temp -> left;
            }
        }
        return root;
    }
};