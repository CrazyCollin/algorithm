struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head){
        if (head==nullptr||head->next==nullptr){
            return head;
        }
        auto slow=head;
        auto fast=head->next->next;
        while (fast!=nullptr&&fast->next!=nullptr) {
            slow=slow->next;
            fast=fast->next->next;
        }
        auto right=mergeSort(slow->next);
        slow->next=nullptr;
        auto left=mergeSort(head);
        return merge(left,right);
    }

    ListNode* merge(ListNode* left,ListNode* right){
        auto dummyNode = new ListNode(-1);
        auto curr= dummyNode;
        while (left!=nullptr&&right!=nullptr) {
            if (left->val<right->val){
                curr->next=left;
                left=left->next;
            }else {
                curr->next=right;
                right=right->next;
            }
            curr=curr->next;
        }
        if (left==nullptr){
            curr->next=right;
        }
        if (right==nullptr){
            curr->next=left;
        }
        return dummyNode->next;
    }
};