//
// Created by LazyCollin on 2023/3/21.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        auto midNode= findMidNode(head);
        auto l1=head,l2=midNode->next;
        midNode->next= nullptr;
        l2= reverseList(l2);
        mergeList(l1,l2);
    }

    ListNode* findMidNode(ListNode* head){
        auto slow=head;
        auto fast=head;
        while (fast->next!= nullptr&&fast->next->next!= nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
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

    void mergeList(ListNode* l1,ListNode* l2){
        ListNode* tmp1;
        ListNode* tmp2;
        while (l1!= nullptr&&l2!= nullptr){
            tmp1=l1->next;
            tmp2=l2->next;
            l1->next=l2;
            l1=tmp1;
            l2->next=l1;
            l2=tmp2;
        }
    }
};