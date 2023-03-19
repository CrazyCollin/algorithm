#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto res=vector<vector<int>>();
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for (auto interval:intervals){
            if (interval[0]<=res.back()[1]){
                res.back()[1]=max(res.back()[1],interval[1]);
            }else {
                res.push_back(interval);
            }
        }
        return res;
    }
};