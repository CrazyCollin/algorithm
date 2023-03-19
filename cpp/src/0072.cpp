#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1=word1.size();
        int size2=word2.size();
        auto dp=vector<vector<int>>(size1+1,vector<int>(size2+1));
        for (int i=1; i<=size1; i++) {
            dp[i][0]=i;
        }
        for (int i=1; i<=size2; i++) {
            dp[0][i]=i;
        }
        for (int i=1; i<=size1; i++) {
            for (int j=1; j<=size2; j++) {
                if (word1[i-1]==word2[j-1]) {
                    dp[i][j]=dp[i-1][j-1];
                } else {
                    dp[i][j]=min(
                        dp[i-1][j]+1,
                        dp[i][j-1]+1,
                        dp[i-1][j-1]+1
                    );
                }
            }
        }
        return dp[size1][size2];
    }

    int min(int a,int b,int c){
        return std::min(std::min(a,b),c);
    }
};

auto main()->int{
    string word1;
    string word2;
    std::getline(std::cin,word1);
    std::getline(std::cin,word2);
    
}