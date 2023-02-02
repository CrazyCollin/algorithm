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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head== nullptr){
            return nullptr;
        }
        auto start=head;
        auto end=head;
        for (int i = 0; i < k; ++i) {
            // return head if list's len is less than K
            if (end== nullptr){
                return head;
            }
            end=end->next;
        }
        // after reverse, start is the last one in list
        auto endNode= reverse(start,end);
        start->next= reverseKGroup(end,k);
        return endNode;
    }
    // [head,tail)
    ListNode* reverse(ListNode* head,ListNode* tail){
        ListNode* prev= nullptr;
        auto curr=head;
        while (curr!=tail){
            auto tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
    }
};