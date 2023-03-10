//
// Created by 20904 on 2023/3/11.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int size=nums.size();
        int max_res=1;
        int count=1;
        for (int i = 1; i < size; ++i) {
            if (nums[i]>nums[i-1]){
                count+=1;
                max_res= max(max_res,count);
            } else{
                count=1;
            }
        }
        return max_res;
    }
};