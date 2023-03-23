//
// Created by collin on 2023/1/19.
//

#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while (start<=end){
            int mid=(start+end)/2;
            if (nums[mid]==target){
                return mid;
            } else if (nums[mid]<mid){
                start=mid+1;
            } else{
                end=mid-1;
            }
        }
        return -1;
    }
};