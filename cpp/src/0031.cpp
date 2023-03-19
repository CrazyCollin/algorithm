#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // 两次遍历，找到一个逆序对就进行交换，再对i+1到最后的地方进行反转
    void nextPermutation(vector<int>& nums) {
        for (int i=nums.size()-1; i>=0;i--) {
            for (int j=nums.size()-1; j>i; j--) {
                if (nums[i]<nums[j]) {
                    swap(nums[i],nums[j]);
                    reverse(nums.begin()+i+1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(),nums.end());
    }
};