//
// Created by collin on 2023/2/3.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow=head;
        auto fast=head;
        while (fast!= nullptr&&fast->next!= nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast){
                return true;
            }
        }
        return false;
    }
};