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
  //SC: O(H)
class Solution {
public:
    void inOrder(TreeNode* node, int &k, int &ans){
        if(node == NULL || !k) return;

        inOrder(node -> left, k, ans);
        k--;
        if(!k) {
            ans = node -> val;
            return;
        }    
        inOrder(node -> right, k, ans);

    }

    int kthSmallest(TreeNode* root, int k) {
       int ans;
       inOrder(root, k, ans);
       return ans;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        int ans;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node -> left;
            }
            else {
                if(st.empty()) break;
                node = st.top();
                st.pop();
                k--;
                if(!k) {
                    ans = node -> val;
                    break;
                }
                node = node -> right;
            }
        }
        return ans;
    }
};

//SC: O(1) MORRIS TRAVERSAL
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        TreeNode* curr = root;

        while(curr != NULL){
            if(curr -> left == NULL){
                k--;
                if(!k){
                    ans = curr -> val;
                    break;
                }
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
        return ans;
    }
};