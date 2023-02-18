//
// Created by collin on 2023/2/18.
//
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> window;
        int left=0,right=0;
        int res=0;
        while (right<s.size()){
            char c=s[right];
            right+=1;
            window[c]+=1;
            // shrink left window
            while (window[c]>1){
                char d=s[left];
                left+=1;
                window[d]-=1;
            }
            res= max(res,right-left);
        }
        return res;
    }
};