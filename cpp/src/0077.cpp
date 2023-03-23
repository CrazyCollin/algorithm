#include <ostream>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combine(int n, int k) {
        tmp=vector<int>(k,0);
        dfs(n, k, 1);
        return res;
    }

    void dfs(int n,int k,int start){
        if (tmp.size()==k) {
            res.push_back(tmp);
            return;
        }
        for (int i=start; i<=n; i++) {
            tmp.push_back(i);
            dfs(n,k,i+1);
            tmp.pop_back();
        }
    }
};

auto main()->int {
    int n,k;
    std::cin>>n>>k;
    Solution solution;
    auto res=solution.combine(n, k);
    for (const auto& item : res) {
        for (auto i : item) {
            std::cout<<i<<"";
        }
        std::cout<<std::endl;
    }
    return 0;
}
