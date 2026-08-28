#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; 

//TC : O(N)
//SC : O(N)
class Solution {
public:
    void inOrder(Node* node, vector<Node*> &arr) {
        if (node == NULL) return;

        inOrder(node->left, arr);
        arr.push_back(node);
        inOrder(node->right, arr);
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> ans;
        vector<Node*> res(2, NULL);

        inOrder(root, ans);

        int n = ans.size();

        for(int i = 0; i < n; i++) {
            if(ans[i]->data < key) {
                res[0] = ans[i];       
            }
            else if(ans[i]->data > key) {
                res[1] = ans[i];       
                break;
            }
            else {
                if(i > 0) res[0] = ans[i - 1];
                if(i < n - 1) res[1] = ans[i + 1];
                break;
            }
        }

        return res;
    }
};

//TC : O(H)
//SC : O(1)
class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        Node* curr = root;
        while (curr != NULL) {
            if (curr->data < key) {
                pre = curr;
                curr = curr->right;
            }
            else curr = curr->left;
        }

        curr = root;
        while (curr != NULL) {
            if (curr->data > key) {
                suc = curr;
                curr = curr->left;
            }
            else curr = curr->right;
        }

        return {pre, suc};
    }
};