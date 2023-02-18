//
// Created by collin on 2023/2/10.
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
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto curr1=l1;
        auto curr2=l2;
        auto dummyHead=new ListNode(-1);
        auto curr=dummyHead;
        int carry=0;
        while (curr1!= nullptr||curr2!= nullptr||carry>0){
            // plus carry
            int val=carry;
            if (curr1!= nullptr){
                val+=curr1->val;
                curr1=curr1->next;
            }
            if (curr2!= nullptr){
                val+=curr2->val;
                curr2=curr2->next;
            }
            carry=val/10;
            val=val%10;
            curr->next=new ListNode(val);
            curr=curr->next;
        }
        return dummyHead->next;
    }
};

struct Example{
    ListNode* l1;
    ListNode* l2;
    ListNode* ans;
};

ListNode* buildList(vector<int> nums){

}

