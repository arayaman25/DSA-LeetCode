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
    void postOrder(TreeNode* node, vector<int> &arr){
            if(node == NULL) return;

            postOrder(node -> left, arr);
            postOrder(node -> right, arr);
            arr.push_back(node -> val);
        }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};

// iterative , single stack
// TC : O(N) SC: O(2N) // iterative , single stack
// TC : O(2N) SC: O(N) 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root == NULL) return postorder;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            root = st1.top();
            st1.pop();
            st2.push(root);

            if (root->left != NULL) {
                st1.push(root->left);
            }

            if (root->right != NULL) {
                st1.push(root->right);
            }
        }

        while (!st2.empty()) {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};


// iterative , single stack
// TC : O(2N) SC: O(N) 

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* temp;

        while (cur != nullptr || !st.empty()) {

            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                temp = st.top()->right;

                if (temp == nullptr) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else {
                    cur = temp;
                }
            }
        }

        return ans;
    }
};