//
// Created by collin on 2023/3/5.
//

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==nullptr){
            return false;
        }
        targetSum-=root->val;
        if (root->left==nullptr&&root->right==nullptr){
            return targetSum==0;
        }
        return hasPathSum(root->left,targetSum)|| hasPathSum(root->right,targetSum);
    }
};