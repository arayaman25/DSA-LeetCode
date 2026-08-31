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
    void inorder(TreeNode* root, vector<int>& arr){
        if(root == NULL) return ;
        inorder(root -> left, arr);
        arr.push_back(root -> val);
        inorder(root -> right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size();
        int l = 0 , r = n - 1;
        while(l < r){
            if(arr[l] + arr[r] == k) return true;
            else if(arr[l] + arr[r] > k) r--;
            else l++;
        }
        return false;
    }
};