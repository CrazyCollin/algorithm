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

#include <unordered_map>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//    std::unordered_set<ListNode*> set;
//    ListNode *detectCycle(ListNode *head) {
//        auto curr=head;
//        while (curr!= nullptr){
//            set.insert(curr);
//            if (set.count(curr->next)){
//                return curr->next;
//            }
//            curr=curr->next;
//        }
//        return nullptr;
//    }
//};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow=head;
        auto fast=head;
        while (fast!= nullptr&&fast->next!= nullptr){
            slow=slow->next;
            fast=fast->next->next;
            // two pointer come together
            if (slow==fast){
                auto curr1=head;
                auto curr2=slow;
                while (curr1!=curr2){
                    curr1=curr1->next;
                    curr2=curr2->next;
                }
                return curr1;
            }
        }
        return nullptr;
    }
};