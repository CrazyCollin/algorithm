//
// Created by LazyCollin on 2023/3/21.
//
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        // carry代表进位数量
        int carry=0;
        int i=num1.size()-1;
        int j=num2.size()-1;
        while (i>=0||j>=0||carry!=0){
            if (num1[i]>=0){
                carry+=num1[i]-'0';
            }
            if (num2[j]>=0){
                carry+=num2[j]-'0';
            }
            res+= to_string(carry%10);
            carry/=10;
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};