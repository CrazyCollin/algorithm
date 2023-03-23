//
// Created by LazyCollin on 2023/3/21.
//
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size()<=1){
            return nums.size();
        }
        auto dp= vector<int>(nums.size(),1);
        int res=0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i]>nums[j]){
                    dp[i]= max(dp[i],dp[j]+1);
                }
                res= max(dp[i],res);
            }
        }
        return res;
    }
};