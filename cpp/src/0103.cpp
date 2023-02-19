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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        auto result= vector<vector<int>>();
        if (root== nullptr){
            return result;
        }
        int flag=1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int length=q.size();
            auto tmp= vector<int>();
            for (int i = 0; i < length; ++i) {
                auto node=q.front();
                q.pop();
                if (flag%2!=0){
                    tmp.insert(tmp.end(),node->val);
                } else{
                    tmp.insert(tmp.begin(),node->val);
                }
                if (node->left!= nullptr){
                    q.push(node->left);
                }
                if (node->right!= nullptr){
                    q.push(node->right);
                }
            }
            flag+=1;
            result.push_back(tmp);
        }
        return result;
    }
};