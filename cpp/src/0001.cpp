//
// Created by collin on 2023/1/7.
//
#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i=0; i<nums.size(); i++) {
            if (map.count(target-nums[i])) {
                return vector<int>{i,map[target-nums[i]]};
            }
            map[nums[i]]=i;
        }
        return vector<int>{};
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    while (n--) {
        int item;
        cin>>item;
        nums.push_back(item);
    }
    int target;
    cin>>target;
    Solution solution;
    auto res=solution.twoSum(nums, target);
    for (int i=0; i<nums.size(); i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}