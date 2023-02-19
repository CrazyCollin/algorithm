//
// Created by collin on 2023/2/20.
//
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root== nullptr){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int length=q.size();
            for (int i = 0; i < length; ++i) {
                auto node=q.front();
                q.pop();
                if (i==length-1){
                    result.push_back(node->val);
                }
                if (node->left!= nullptr){
                    q.push(node->left);
                }
                if (node->right!= nullptr){
                    q.push(node->right);
                }
            }
        }
        return result;
    }
};