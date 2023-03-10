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
//    TreeNode* invertTree(TreeNode* root) {
//        if (root== nullptr){
//            return nullptr;
//        }
//        auto left_node= invertTree(root->left);
//        auto right_node= invertTree(root->right);
//        root->left=right_node;
//        root->right=left_node;
//        return root;
//    }
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }
    void traverse(TreeNode* root) {
        if (root== nullptr){
            return;
        }
        auto tmp_node=root->left;
        root->left=root->right;
        root->right=tmp_node;
        traverse(root->left);
        traverse(root->right);
   }
};

auto main()->int {

};