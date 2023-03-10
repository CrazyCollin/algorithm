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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        return build(nums,low,high);
    }

    TreeNode* build(vector<int>& nums,int low,int high){
        if (low>high){
            return nullptr;
        }
        int root_index=-1;
        int max_val=INT_MIN;
        for (int i = low; i <= high; ++i) {
            if (max_val<nums[i]){
                root_index=i;
                max_val=nums[i];
            }
        }
        auto root=new TreeNode(max_val);
        root->left=build(nums,low,root_index-1);
        root->right=build(nums,root_index+1,high);
        return root;
    }
};