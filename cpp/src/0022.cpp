#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> res;
    string tmp;
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return res;
    }

    // left and right are parentheses nums
    void dfs(int n,int left,int right){
        if (tmp.size()==2*n) {
            res.push_back(tmp);
            return;
        }

        if (left<n) {
            tmp.push_back('(');
            dfs(n, left+1,right);
            tmp.pop_back();
        }
        if (right<left) {
            tmp.push_back(')');
            dfs(n,left,right+1);
            tmp.pop_back();
        }
    }
};