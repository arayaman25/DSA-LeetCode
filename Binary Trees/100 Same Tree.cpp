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
  
// TC : O(N) SC: O(H)

class Solution {
public:
    bool isSame(TreeNode* root1, TreeNode* root2){        
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;

        if(root1->val != root2->val) return false;

        return isSame(root1 -> left, root2 -> left) && isSame(root1 -> right, root2 -> right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        return isSame(p, q);
    }
};


// TC : O(N) SC: O(N)
class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()) {
            TreeNode* first = q1.front();
            TreeNode* second = q2.front();
            q1.pop();
            q2.pop();
            if(first->val != second->val) return false;
          
            if(first->left && second->left) {
                q1.push(first->left);
                q2.push(second->left);
            } 
            else if(first->left || second->left) return false;

            if(first->right && second->right) {
                q1.push(first->right);
                q2.push(second->right);
            } 
            else if(first->right || second->right) return false;
        }
        return true; 
    }
};