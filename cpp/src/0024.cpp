//
// Created by collin on 2023/2/2.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head== nullptr){
            return nullptr;
        }
        auto dummyHead= new ListNode(-1,head);
        auto curr=dummyHead;
        while (curr->next!= nullptr&&curr->next->next!= nullptr){
            auto tmp1=curr->next;
            auto tmp2=curr->next->next->next;
            curr->next=tmp1->next;
            curr->next->next=tmp1;
            tmp1->next=tmp2;
            curr=curr->next->next;
        }
        head=dummyHead->next;
        delete dummyHead;
        return head;
    }
};