#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        return res;
    }

    void dfs(vector<int>& nums,int start){
        res.push_back(tmp);
        for (int i=start; i<nums.size(); i++) {
            tmp.push_back(nums[i]);
            dfs(nums,i+1);
            tmp.pop_back();
        }
    }
};