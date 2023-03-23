//
// Created by LazyCollin on 2023/3/21.
//

// https://leetcode.cn/problems/median-of-two-sorted-arrays/solutions/485550/zong-he-bai-jia-ti-jie-zong-jie-zui-qing-xi-yi-don/
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int left=(m+n+1)/2;
        int right=(m+n+2)/2;
        return (getKth(nums1, 0, nums2, 0, left)+
                getKth(nums1, 0, nums2, 0, right))/2.0;
    }
    // i，j分别是nums1和nums2的起始位置
    int getKth(vector<int>& nums1,int i,
               vector<int>& nums2,int j,int k){
        // 假如nums1为空，则在nums2中找第k个元素，
        if (i>=nums1.size()) {
            return nums2[j+k-1];
        }
        if (j>=nums2.size()) {
            return nums1[i+k-1];
        }
        // 递归出口
        if (k==1) {
            return min(nums1[i],nums2[j]);
        }
        // 这两个数组的第k/2小的数字
        int midVal1=(i+k/2-1<nums1.size())?nums1[i+k/2-1]:INT_MAX;
        int midVal2=(j+k/2-1<nums2.size())?nums2[j+k/2-1]:INT_MAX;
        if (midVal1<midVal2){
            return getKth(nums1, i+k/2, nums2, j, k-k/2);
        }else {
            return getKth(nums1, i, nums2, j+k/2, k-k/2);
        }
    }
};