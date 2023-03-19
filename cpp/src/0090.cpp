#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        auto used=vector<bool>(nums.size(),false);
        sort(nums.begin(),nums.end());
        dfs(nums,used,0);
        return res;
    }

    void dfs(vector<int>& nums,vector<bool>& used,int start){
        res.push_back(tmp);
        for (int i=start; i<nums.size(); i++) {
            if (i>0&&nums[i]==nums[i-1]&&!used[i-1]) {
                continue;
            }
            used[i]=true;
            tmp.push_back(nums[i]);
            dfs(nums,used,i+1);
            tmp.pop_back();
            used[i]=false;
        }
    }
};