//
// Created by collin on 2023/2/20.
//
#include <string>

using namespace std;

class Solution {
public:
    int left=0;
    int right=0;
    int max_length=0;
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); ++i) {
            extend(s,i,i,s.size());
            extend(s,i,i+1,s.size());
        }
        return s.substr(left,max_length);
    }
    void extend(const string& s,int i,int j,int k){
        while (i>=0&&j<k&&s[i]==s[j]){
            if (j-i+1>max_length){
                left=i;
                right=j;
                max_length=j-i+1;
            }
            i-=1;
            j+=1;
        }
    }
};