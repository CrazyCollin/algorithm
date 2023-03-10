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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int right=inorder.size()-1;
        return build(inorder,0,right,postorder,0,right);
    }

    TreeNode* build(vector<int>& inorder,int in_left,int in_right,
                    vector<int>& postorder,int post_left,int post_right){
        if (in_left>in_right){
            return nullptr;
        }
        int root_val=postorder[post_right];
        int in_root_index=-1;
        for (int i = in_left; i <=in_right; ++i) {
            if (root_val==inorder[i]){
                in_root_index=i;
                break;
            }
        }
        int left_size=in_root_index-in_left;
        auto root=new TreeNode(root_val);
        root->left= build(inorder,in_left,in_root_index-1,
                          postorder,post_left,post_left+left_size-1);
        root->right= build(inorder,in_root_index+1,in_right,
                           postorder,post_left+left_size,post_right-1);
        return root;
    }
};