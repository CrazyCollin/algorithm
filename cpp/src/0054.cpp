#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0,right=matrix[0].size()-1;
        int top=0,bottom=matrix.size()-1;
        int len=matrix.size()*matrix[0].size();
        auto res=vector<int>(len,0);
        int index=0;
        while (index<len){
            for (int i=left; i<=right&&index<len; i++) {
                res[index]=matrix[top][i];
                index++;
            }
            top++;
            for (int i=top; i<=bottom&&index<len; i++) {
                res[index]=matrix[i][right];
                index++;
            }
            right--;
            for (int i=right; i>=left&&index<len; i--) {
                res[index]=matrix[bottom][i];
                index++;
            }
            bottom--;
            for (int i=bottom; i>=top&&index<len; i--) {
                res[index++]=matrix[i][left];
            }
            left++;
        }
        return res;
    }
};