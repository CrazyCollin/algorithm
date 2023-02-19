//
// Created by collin on 2023/2/19.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MIN;
        if (n==0){
            return 0;
        }
        auto dp=vector<int>(n);
        dp[0]=nums[0];
        res=dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i]= max(nums[i],dp[i-1]+nums[i]);
            res= max(res,dp[i]);
        }
        return res;
    }
};