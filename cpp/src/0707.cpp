//
// Created by collin on 2023/2/2.
//
#include <vector>

class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val):val(val),next(nullptr){}
    };
    MyLinkedList() {
        size=0;
        dummyHead=new ListNode(-1);
    }

    int get(int index) {
        if (index>=size||index<0){
            return -1;
        }
        auto curr=dummyHead;
        for (int i = 0; i < index; ++i) {
            curr=curr->next;
        }
        return curr->next->val;
    }

    void addAtHead(int val) {
        auto newNode=new ListNode(val);
        newNode->next=dummyHead->next;
        dummyHead->next=newNode;
        size+=1;
    }

    void addAtTail(int val) {
        auto curr=dummyHead;
        while (curr->next!= nullptr){
            curr=curr->next;
        }
        auto newNode=new ListNode(val);
        curr->next=newNode;
        size+=1;
    }

    void addAtIndex(int index, int val) {
        if (index==size){
            addAtTail(val);
            return;
        } else if (index>size){
            return;
        }else if (index<0){
            addAtHead(val);
            return;
        }
        auto curr=dummyHead;
        auto newNode=new ListNode(val);
        for (int i = 0; i < index; ++i) {
            curr=curr->next;
        }
        newNode->next=curr->next;
        curr->next=newNode;
        size+=1;
    }

    void deleteAtIndex(int index) {
        if (index>=size||index<0){
            return;
        }
        auto curr=dummyHead;
        for (int i = 0; i < index; ++i) {
            curr=curr->next;
        }
        auto tmp=curr->next;
        curr->next=tmp->next;
        delete tmp;
        size-=1;
    }
private:
    int size;
    ListNode* dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */