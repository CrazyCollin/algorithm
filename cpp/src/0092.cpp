//
// Created by collin on 2023/2/20.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummyNode=new ListNode(-1);
        dummyNode->next=head;
        auto pre=dummyNode;
        auto curr=head;
        // curr移动到left的位置上，pre在前面
        for (int i=0; i<left-1; i++) {
            pre=pre->next;
            curr=curr->next;
        }

        // 反转指定区域的链表[left-1,right-1] len:right-left
        for (int i=0; i<right-left; i++) {
            auto tmp=curr->next;
            curr->next=tmp->next;
            tmp->next=pre->next;
            pre->next=tmp;
        }
        return dummyNode->next;
    }
};