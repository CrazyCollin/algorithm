//
// Created by collin on 2023/3/6.
//

#include <algorithm>
#include <climits>
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
    int max_sum=INT_MIN;
    int maxPathSum(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        dfs(root);
        return max_sum;
    }

    int dfs(TreeNode* root){
        if (root==nullptr) {
            return 0;
        }
        // 如果最大路径和小于0，及对总路径和做负贡献应当舍弃
        int left=std::max(dfs(root->left),0);
        int right=std::max(dfs(root->right),0);
        // 根+左+右
        max_sum=std::max(max_sum,root->val+left+right);
        // 根+左 根+右边 的情况，需要递归
        return std::max(root->val+left,root->val+right);
    }
};