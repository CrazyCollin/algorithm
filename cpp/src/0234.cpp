//
// Created by collin on 2023/2/3.
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
    bool isPalindrome(ListNode* head) {
        auto slow=head;
        auto fast=slow;
        while (fast!= nullptr&&fast->next!= nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        if (fast!= nullptr){
            slow=slow->next;
        }
        auto curr1=head;
        auto curr2= reverse(slow);
        while (curr2!= nullptr){
            if (curr1->val!=curr2->val){
                return false;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev= nullptr;
        auto curr=head;
        while (curr!= nullptr){
            auto tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
    }
};