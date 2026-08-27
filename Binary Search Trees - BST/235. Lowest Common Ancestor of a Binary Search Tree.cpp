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


  // TC : O(H) 
  //SC: O(1)
  
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        while(root != NULL){
            int curr = root -> val;
            if(curr  > p -> val && curr > q -> val) root = root -> left;
            else if( curr < p -> val &&  curr < q -> val) root = root -> right;
            else return root;
             
        }
        return root;
    }
};