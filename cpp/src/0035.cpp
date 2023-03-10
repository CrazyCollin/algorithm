//
// Created by collin on 2023/2/20.
//
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length=nums.size();
        int left=0;
        int right=length-1;
        while (left<=right){
            int mid=left+(right-left)/2;
            if (nums[mid]<target){
                left=mid+1;
            } else if (nums[mid]>target){
                right=mid-1;
            } else{
                return mid;
            }
        }
        return right;
    }
};