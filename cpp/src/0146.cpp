//
// Created by collin on 2023/1/7.
//
#include <unordered_map>

using namespace std;

struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k,int v):key(k),val(v),prev(nullptr),next(nullptr){}
};

class LinkedList{
    Node* head;
    Node* tail;
public:
    LinkedList(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void push_front(Node* node){
        node->prev=head;
        node->next=head->next;
        head->next=node;
        node->next->prev=node;
    }

    void erase(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    Node* back(){
        return tail->prev;
    }

    void pop_back(){
        erase(tail->prev);
    }
};

class LRUCache {
    int cap;
    unordered_map<int,Node*> node_map;
    LinkedList* cache;
public:
    LRUCache(int capacity) {
        cap=capacity;
        cache=new LinkedList();
    }

    int get(int key) {
        if (node_map.find(key)!=node_map.end()){
            auto node=node_map[key];
            cache->erase(node);
            cache->push_front(node);
            return node->val;
        }else{
            return -1;
        }
    }

    void put(int key, int value) {
        if (node_map.find(key)!=node_map.end()){
            auto node=node_map[key];
            node->val=value;
            cache->erase(node);
            cache->push_front(node);
        } else{
            // exceed capacity, remove last used one
            if (node_map.size()==cap){
                auto node=cache->back();
                node_map.erase(node->key);
                cache->pop_back();
            }
            auto node=new Node(key,value);
            node_map[key]=node;
            cache->push_front(node);
        }
    }
};