#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        auto used=vector<bool>(nums.size(),false);
        sort(nums.begin(),nums.end());
        dfs(nums,used);
        return res;
    }

    void dfs(vector<int>& nums,vector<bool>& used){
        if (tmp.size()==nums.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (used[i]){
                continue;
            }
            if (i>0&&nums[i]==nums[i-1]&&!used[i-1]) {
                continue;
            }
            used[i]=true;
            tmp.push_back(nums[i]);
            dfs(nums,used);
            tmp.pop_back();
            used[i]=false;
        }
    }
};