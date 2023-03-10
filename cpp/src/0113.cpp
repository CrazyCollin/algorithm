//
// Created by collin on 2023/3/5.
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
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root== nullptr){
            return res;
        }
        recurse(root,targetSum);
        return res;
    }

    void recurse(TreeNode* root,int targetSum){
        if (root== nullptr){
            return;
        }
        tmp.push_back(root->val);
        targetSum-=root->val;
        if (root->left== nullptr&&root->right== nullptr&&targetSum==0){
            res.emplace_back(tmp);
        }
        recurse(root->left,targetSum);
        recurse(root->right,targetSum);
        tmp.pop_back();
    }
};