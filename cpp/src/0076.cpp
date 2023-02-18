//
// Created by collin on 2023/2/18.
//
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> needs,window;
        int left=0,right=0;
        int valid=0;
        // record result string's start index and length
        int start=0,len=INT_MAX;
        for (auto c:t) {
            needs[c]+=1;
        }
        while (right<s.size()){
            char c=s[right];
            right+=1;
            // if current char is needed
            if (needs.count(c)){
                window[c]+=1;
                if (needs[c]==window[c]){
                    valid+=1;
                }
            }
            while (valid==needs.size()){
                // update result
                if (right-left<len){
                    start=left;
                    len=right-left;
                }
                char d=s[left];
                left+=1;
                if (needs.count(d)){
                    if (needs[d]==window[d]){
                        valid-=1;
                    }
                    window[d]-=1;
                }
            }
        }
        if (len==INT_MAX){
            return "";
        }
        return s.substr(start,len);
    }
};

int main(){

    Solution solution;
    string s = "bacaaaabc";
    string t = "bc";
    cout << solution.minWindow(s, t) << endl;

    return 0;
}