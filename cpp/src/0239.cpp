#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MonotonicQueue window;
        for (int i=0; i<k; i++) {
            window.push(nums[i]);
        }
        res.push_back(window.max());
        for(int i=k;i<nums.size();i++){
            window.pop(nums[i-k]);
            window.push(nums[i]);
            res.push_back(window.max());
        }
        return res;
    }
private:
    class MonotonicQueue{
        public:
            void push(int n){
                while(!data.empty()&&data.back()<n){
                    data.pop_back();
                }
                data.push_back(n);
            }
            void pop(int n){
                if(!data.empty()&&data.front()==n){
                    data.pop_front();
                }
            }
            int max(){
                return data.front();
            }
        private:
            deque<int> data;
    };
};