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
    ListNode* removeElements(ListNode* head, int val) {
        auto dummyNode= new ListNode(-1,head);
        auto curr=dummyNode;
        while (curr->next!= nullptr){
            if (curr->next->val==val){
                auto tmp=curr->next;
                curr->next=curr->next->next;
                delete tmp;
            } else{
                curr=curr->next;
            }
        }
        head=dummyNode->next;
        delete dummyNode;
        return head;
    }
};