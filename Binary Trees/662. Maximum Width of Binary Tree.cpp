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


// TC : O(N) 
//SC: O(N)
class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;

        long long maxi = INT_MIN;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            long long l = 0 , r = 0;
            for(int i = 0 ; i < size ; i++){
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                long long ind = p.second;

                if(i == 0) l = ind; // leftmost
                if(i == size - 1)  r = ind; // right

                if(node -> left) q.push({node -> left, 2 * ind + 1});
                if(node -> right) q.push({node -> right, 2 * ind + 2});

            }
                maxi = max(maxi, r - l + 1);

        }
            return (int)maxi;

    }
};