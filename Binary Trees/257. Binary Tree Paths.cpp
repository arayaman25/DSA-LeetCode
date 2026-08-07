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



//Time: O(N)
//Space: O(H)
class Solution {
public:
    void getPath(TreeNode* root, vector<string> &ans, string temp){
        if(root == NULL) return;

        if(root ->left == NULL && root ->right == NULL){
            if(temp.size() > 0){
                temp = temp + '-' + '>';
            }
            temp += to_string(root -> val);
            ans.push_back(temp);
            return;
        }

        if(temp.size() > 0){
            temp = temp + '-' + '>';
        }

        temp += to_string(root -> val);
        getPath(root -> left, ans, temp);
        getPath(root -> right, ans, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp="";
        getPath(root, ans, temp);    
        return ans;
    }
};