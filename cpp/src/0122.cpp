//
// Created by collin on 2023/2/20.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
//        int result=0;
//        for (int i = 1; i < prices.size(); ++i) {
//            int diff=prices[i]-prices[i-1];
//            if (diff>0){
//                result+=diff;
//            }
//        }
//        return result;
        int length=prices.size();
        vector<vector<int>> dp(length, vector<int>(2,0));
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        for (int i = 1; i < length; ++i) {
            dp[i][0]= max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1]= max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }
        return dp[length-1][1];
    }
};