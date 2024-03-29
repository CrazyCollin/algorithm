//
// Created by collin on 2023/2/20.
//
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<int> result;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
       return result;
    }

    void dfs(TreeNode* root){
        if (root== nullptr){
            return;
        }
        dfs(root->left);
        result.push_back(root->val);
        dfs(root->right);
    }
};