//
// Created by LazyCollin on 2023/3/22.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        auto dp=vector<vector<int>>(m+1,vector<int>(n+1,0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                } else{
                    dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return m+n-2*dp[m][n];
    }
};