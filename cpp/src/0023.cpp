//
// Created by LazyCollin on 2023/3/21.
//
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int left=0;
        int right=lists.size()-1;
        return merge(lists,left,right);
    }

    ListNode* merge(vector<ListNode*>& lists,int left,int right){
        if (left==right){
            return lists[left];
        }
        if (left>right){
            return nullptr;
        }
        auto mid=(left+right)/2;
        auto l1= merge(lists,left,mid);
        auto l2= merge(lists,mid+1,right);
        return mergeTwoList(l1,l2);
    }

    ListNode* mergeTwoList(ListNode* l1,ListNode* l2){
        auto dummyNode=new ListNode(-1);
        auto curr=dummyNode;
        while (l1!= nullptr&&l2!= nullptr){
            if (l1->val>l2->val){
                curr->next=l1;
                l1=l1->next;
            } else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if (l1== nullptr){
            curr->next=l2;
        } else{
            curr->next=l1;
        }
    }
};

ListNode* generateList(const vector<int>& nums){
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

auto main()->int {
    Solution solution;
    auto list1= generateList(vector<int>{1,4,5});
    auto list2= generateList(vector<int>{1,3,4});
    auto list3= generateList(vector<int>{2,6});
    auto case1= vector<ListNode*>();
    case1.push_back(list1);
    case1.push_back(list2);
    case1.push_back(list3);
    auto expected_result=solution.mergeKLists(case1);
    while (expected_result!= nullptr){
        cout<<expected_result->val<<" ";
        expected_result=expected_result->next;
    }
}