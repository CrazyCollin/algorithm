//
// Created by collin on 2023/3/6.
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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int right=preorder.size()-1;
        return build(preorder,0,right,inorder,0,right);
    }

    TreeNode* build(vector<int>& preorder,int pre_left,int pre_right,
                    vector<int>& inorder,int in_left,int in_right){
        if (pre_left>pre_right){
            return nullptr;
        }
        int root_val=preorder[pre_left];
        int in_root_index=-1;
        for (int i = in_left; i <=in_right; ++i) {
            if (root_val==inorder[i]){
                in_root_index=i;
                break;
            }
        }
        int left_size=in_root_index-in_left;
        auto root=new TreeNode(root_val);
        root->left= build(preorder,pre_left+1,pre_left+left_size,
                          inorder,in_left,in_root_index-1);
        root->right= build(preorder,pre_left+left_size+1,pre_right,
                           inorder,in_root_index+1,in_right);
        return root;
    }
};