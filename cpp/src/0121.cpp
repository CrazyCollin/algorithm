#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
//        int low=INT_MAX;
//        int result=0;
//        for (int i = 0; i < prices.size(); ++i) {
//            low= min(low,prices[i]);
//            result= max(result,prices[i]-low);
//        }
//        return result;
        int length=prices.size();
        vector<vector<int>> dp(length, vector<int>(2));
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        for (int i = 1; i < length; ++i) {
            dp[i][0]= max(dp[i-1][0],-prices[i]);
            dp[i][1]= max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }
        return dp[length-1][1];
    }
};