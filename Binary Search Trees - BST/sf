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


  // TC : O(N) + O(N) + O(N log N) 
  //SC: O(N)

  class Solution {
public:
    void restore(TreeNode* root, vector<int>& arr, int &i){
        if(root == NULL) return ;
        restore(root -> left, arr, i);
        root -> val = arr[i++];
        restore(root -> right, arr, i);
    }

    void inorder(TreeNode* root, vector<int>& arr){
        if(root == NULL) return ;
        inorder(root -> left, arr);
        arr.push_back(root -> val);
        inorder(root -> right, arr);
    }

    void recoverTree(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        sort(arr.begin(), arr.end());    
        int i = 0;
        restore(root, arr, i);
    }
};


//Time: O(n)
//Space: O(h) , O(1) with morris


class Solution {
public:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root){
        if(root == NULL) return ;
        inorder(root -> left);
        if(prev && (root -> val < prev -> val)){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root -> right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = prev = NULL;
        inorder(root);

        if(first && last) swap(first -> val, last -> val);
        else if(first && middle) swap(first -> val, middle -> val);
    }
};