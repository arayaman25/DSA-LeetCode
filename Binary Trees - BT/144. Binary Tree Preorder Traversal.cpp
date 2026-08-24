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
    void preOrder(TreeNode* node, vector<int> &arr){
        if(node == NULL) return;

        arr.push_back(node -> val);
        preOrder(node -> left, arr);
        preOrder(node -> right, arr);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(root, ans);
        return ans;
        
    }
};


//iterative
//using stack - LIFO
// TC : O(N) SC: O(N) ie ht of BT

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if(root == NULL) return preOrder;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();

            preOrder.push_back(root -> val);

            if(root -> right) st.push(root -> right);
            if(root -> left) st.push(root -> left);
        }
    

        return preOrder;
        
    }
};