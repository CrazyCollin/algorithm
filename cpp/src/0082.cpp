//
// Created by LazyCollin on 2023/3/21.
//
#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummyNode=new ListNode(-1,head);
        auto pre=dummyNode;
        auto curr=head;
        // 表示是否有重复的节点
        auto flag= false;
        while (curr!= nullptr){
            // 有重复节点
            while (curr->next!= nullptr&&curr->val==curr->next->val){
                curr=curr->next;
                flag= true;
            }
            if (flag){
                pre->next=curr->next;
                flag= false;
            }else {
                pre=curr;
            }
            curr=curr->next;
        }
        return dummyNode->next;
    }
};

ListNode* generateList(std::vector<int>& nums){
    ListNode* head= nullptr;
    ListNode* curr= nullptr;
    for (const auto& num:nums) {
        if (head== nullptr){
            head=new ListNode(num);
            curr=head;
        } else{
            curr->next=new ListNode(num);
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    Solution solution;

    std::vector<int> case1={1,2,3,3,4,4,5};
    auto list1= generateList(case1);
    auto test_list1=solution.deleteDuplicates(list1);
    auto expected_list1= generateList(case1);
    std::cout<<case1.size()<<std::endl;
    for (int i=0;i<case1.size();i++) {
        std::cout<<list1->val<<" ";
        list1=list1->next;
    }
    std::cout<<std::endl;
    return 0;
}

