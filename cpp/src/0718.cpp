//
// Created by 20904 on 2023/3/11.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int max_res=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i-1]==nums2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                if (dp[i][j]>max_res){
                    max_res=dp[i][j];
                }
            }
        }
        return max_res;
    }
};

auto main()->int{
    auto s=Solution();

    return 0;
}