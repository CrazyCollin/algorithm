//
// Created by collin on 2023/2/20.
//
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==p||root==q||root== nullptr){
            return root;
        }
        auto left_node= lowestCommonAncestor(root->left,p,q);
        auto right_node= lowestCommonAncestor(root->right,p,q);
        // handle
        if (left_node== nullptr&&right_node== nullptr){
            return nullptr;
        } else if (left_node!= nullptr&&right_node== nullptr){
            return left_node;
        }else if (left_node== nullptr&&right_node!= nullptr){
            return right_node;
        } else{
            return root;
        }
    }
};