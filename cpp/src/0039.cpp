#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0,0, target);
        return res;
    }

    // 要注意可以重复选择就回溯的时候从start开始，而不是start+1
    void dfs(vector<int>& candidates,int sum,int start,int target){
        if (sum==target) {
            res.push_back(tmp);
            return;
        }
        if (sum>target) {
            return;
        }
        for (int i=start; i<candidates.size(); i++) {
            tmp.push_back(candidates[i]);
            sum+=candidates[i];
            dfs(candidates,sum,i,target);
            sum-=candidates[i];
            tmp.pop_back();
        }
    }
};