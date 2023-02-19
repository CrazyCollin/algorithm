//
// Created by collin on 2023/2/19.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length=nums.size();
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for (int i = 0; i <length; ++i) {
            if (nums[i]>0){
                return result;
            }
            if (i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1;
            int right=length-1;
            while (left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if (sum<0){
                    left+=1;
                }else if (sum>0){
                    right-=1;
                }else{
                    result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while (left<right&&nums[right]==nums[right-1]){
                        right-=1;
                    }
                    while (left<right&&nums[left]==nums[left+1]){
                        left+=1;
                    }
                    left+=1;
                    right-=1;
                }
            }
        }
        return result;
    }
};