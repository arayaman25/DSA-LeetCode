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

//TC : O(n) SC : O(n)
class Solution {
public:
    int maxSum;

    int solve(TreeNode* node){
        if(node == NULL) return 0;

        int lSum = solve(node -> left); 
        int rSum = solve(node -> right); 

        int niche_answer_milgaya = lSum + rSum + node -> val;
        int koi_ek_accha_hai = max(lSum, rSum) + node -> val;
        int sirf_root_accha_hai = node -> val;

        maxSum = max({maxSum, 
                    niche_answer_milgaya, 
                    koi_ek_accha_hai, 
                    sirf_root_accha_hai});

        return max(koi_ek_accha_hai, sirf_root_accha_hai);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};