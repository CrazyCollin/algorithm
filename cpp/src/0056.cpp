#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(auto interval:intervals){
            // 比较当前区间的左端点和上一个区间的右端点
            if(res.back()[1]>=interval[0]){
                res.back()[1]=max(res.back()[1],interval[1]);
            }else{
                res.push_back(interval);
            }
        } 
        return res;
    }
};

auto main() ->int{
    auto s=Solution();
    vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
    auto res=s.merge(intervals);
    return 0;
}