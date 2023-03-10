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
    void flatten(TreeNode* root) {
        if (root== nullptr){
            return;
        }
        flatten(root->left);
        flatten(root->right);
        // transfer left and right node
        auto left_node=root->left;
        auto right_node=root->right;
        root->left= nullptr;
        root->right=left_node;
        auto curr=root;
        while (curr->right!= nullptr){
            curr=curr->right;
        }
        curr->right=right_node;
    }
};