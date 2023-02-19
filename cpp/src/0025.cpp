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
            return head;
        }
        auto start=head;
        auto end=head;
        for (int i = 0; i < k; i++) {
            if (end==nullptr){
                return head;
            }
            end=end->next;
        }
        auto start_node= reverse(start,end);
        start->next= reverseKGroup(end,k);
        return start_node;
    }
    // [head,tail)
    ListNode* reverse(ListNode* head,ListNode* tail){
        auto curr=head;
        ListNode* prev= nullptr;
        while (curr!=tail){
            auto tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
    }
};