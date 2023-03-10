//
// Created by collin on 2023/2/20.
//
#include <vector>

using namespace std;

class Solution {
public:
    // 先判断有序，再在有序的段里面以mid为界限找target，只在有序里面
    int search(vector<int>& nums, int target) {
        int length=nums.size();
        int left=0;
        int right=length-1;
        while (left<=right){
            int mid=left+(right-left)/2;
            if (nums[mid]==target){
                return mid;
            } else if (nums[mid]>=nums[left]){
                if (target>=nums[left]&&target<nums[mid]){
                    right=mid-1;
                } else{
                    left=mid+1;
                }
            } else{
                if (target>nums[mid]&&target<=nums[right]){
                    left=mid+1;
                } else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};