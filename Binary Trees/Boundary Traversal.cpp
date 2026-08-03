#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// Check if a node is a leaf
bool isLeaf(TreeNode* node) {
    return node->left == nullptr && node->right == nullptr;
}

// Add left boundary (excluding leaves)
void addLeftBoundary(TreeNode* root, vector<int>& res) {
    TreeNode* cur = root->left;

    while (cur) {
        if (!isLeaf(cur))
            res.push_back(cur->val);

        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

// Add right boundary (excluding leaves)
void addRightBoundary(TreeNode* root, vector<int>& res) {
    TreeNode* cur = root->right;
    vector<int> temp;

    while (cur) {
        if (!isLeaf(cur))
            temp.push_back(cur->val);

        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

// Add all leaf nodes
void addLeaves(TreeNode* root, vector<int>& res) {
    if (root == nullptr)
        return;

    if (isLeaf(root)) {
        res.push_back(root->val);
        return;
    }

    addLeaves(root->left, res);
    addLeaves(root->right, res);
}

// Boundary Traversal
vector<int> printBoundary(TreeNode* root) {
    vector<int> res;

    if (root == nullptr)
        return res;

    if (!isLeaf(root))
        res.push_back(root->val);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}