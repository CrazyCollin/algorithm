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
        auto slow=dummyHead;
        auto fast=head;
        for (int i = 0; i < n ; ++i) {
            fast=fast->next;
        }
        while (fast!= nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        auto tmp=slow->next;
        slow->next=tmp->next;
        delete tmp;
        return dummyHead->next;
    }
};