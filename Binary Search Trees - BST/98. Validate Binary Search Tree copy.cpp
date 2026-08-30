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
class BSTIterator {
public:
    int i = -1;
    vector<TreeNode*> ans;
    void inOrder(TreeNode* node, vector<TreeNode*> &ans) {
        if (node == NULL) return;

        inOrder(node->left, ans);
        ans.push_back(node);
        inOrder(node->right, ans);
    }

    BSTIterator(TreeNode* root) {
        inOrder(root, ans);
    }
    
    int next() {
        return ans[++i] -> val;
    }
    
    bool hasNext() {
        if(i + 1 < ans.size()) return true;
        return false;
    }
};


// Constructor: O(h) time, where h = height of BST
// next(): O(h) worst case, but O(1) amortized
// hasNext(): O(1) time
// Space: O(h)

class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {   
        TreeNode* node = root;
        while(node != NULL){
            st.push(node);
            node = node -> left;
        }
    }
    
    int next() {
        TreeNode* node = st.top();
        int ans = node -> val;
        st.pop();
        node = node -> right;
        while(node != NULL){
            st.push(node);
            node = node -> left;
        }
        return ans;

    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        return false;
    }
};
