//
// Created by collin on 2023/2/19.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len=nums.size();
        sort(nums,0,len-1);
        return nums;
    }

    void sort(vector<int>& nums,int left_index,int right_index){
        if (left_index<right_index){
            int mid= partition(nums,left_index,right_index);
            sort(nums,left_index,mid-1);
            sort(nums,mid+1,right_index);
        }
    }

    int partition(vector<int>& nums,int left_index,int right_index){
        int pivot_index=std::rand()%(right_index-left_index+1)+left_index;
        swap(nums,left_index,pivot_index);
        int pivot=nums[left_index];
        while (left_index<right_index){
            while (left_index<right_index&&nums[right_index]>=pivot){
                right_index-=1;
            }
            nums[left_index]=nums[right_index];
            while (left_index<right_index&&nums[left_index]<pivot){
                left_index+=1;
            }
            nums[right_index]=nums[left_index];
        }
        nums[left_index]=pivot;
        return left_index;
    }

    static void swap(vector<int>& nums,int left_index,int right_index){
        int tmp=nums[left_index];
        nums[left_index]=nums[right_index];
        nums[right_index]=tmp;
    }
};