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
  //SC: O(N)
class Solution {
public:
    class Info {
    public:
        int min, max, sum;
        bool isBst;
        
        Info(int mi, int ma, int su, bool bst){
            min = mi;
            max = ma;
            sum = su;
            isBst = bst;
        }
    };
    
    int ans = 0;

    Info helper(TreeNode* root){
        if(root == NULL){
            return Info(INT_MAX, INT_MIN, 0, true);
        }

        Info left = helper(root -> left);
        Info right = helper(root -> right);

        if(left.isBst && right.isBst && root -> val > left.max && root -> val < right.min){
            int currMin = min(root -> val, left.min);
            int currMax = max(root -> val, right.max);
            int currSum = left.sum + right.sum + root -> val; 

            ans = max(ans, currSum);

            return Info(currMin, currMax, currSum, true);
        }
        return Info(INT_MIN, INT_MAX, max(left.sum, right.sum), false);
    }

    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};