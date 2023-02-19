//
// Created by collin on 2023/2/19.
//
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int curr=m+n-1,curr1=m-1,curr2=n-1;
        while (curr1>=0&curr2>=0){
            if (nums1[curr1]>=nums2[curr2]){
                nums1[curr]=nums1[curr1];
                curr1-=1;
            } else{
                nums1[curr]=nums2[curr2];
                curr2-=1;
            }
            curr-=1;
        }
        while (curr2>=0){
            nums1[curr]=nums1[curr2];
            curr2-=1;
        }
    }
};