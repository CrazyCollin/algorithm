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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummyHead=new ListNode(-1,head);
        auto prev=dummyHead;
        auto curr=head;
        auto fast=head;
        for (int i = 0; i < n ; ++i) {
            fast=fast->next;
        }
        while (fast!= nullptr){
            fast=fast->next;
            curr=curr->next;
            prev=prev->next;
        }
        prev->next=curr->next;
        return dummyHead->next;
    }
};