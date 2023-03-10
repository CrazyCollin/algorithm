//
// Created by 20904 on 2023/3/11.
//
#include <vector>

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

    std::vector<int> vec;
    int kthSmallest(TreeNode* root, int k) {
        reverse(root);
        return vec[k-1];
    }

    void reverse(TreeNode* root){
        if (root== nullptr){
            return;
        }
        reverse(root->left);
        vec.push_back(root->val);
        reverse(root->right);
   }
};