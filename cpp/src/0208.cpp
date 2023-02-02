//
// Created by collin on 2023/1/19.
//
#include <stdlib.h>
#include <unordered_map>
#include <string>

using namespace std;

class TrieNode{
public:
    TrieNode(){};
    TrieNode(char key){
        key_=key;
    }
    ~TrieNode()=default;
    std::unordered_map<char,TrieNode*> children_;
    bool is_end_{false};
    char key_;
};

class Trie {
public:
    Trie() {
        root_=new TrieNode();
    }

    void insert(string word) {
        auto p=root_;
        for (char a:word) {
            if (!p->children_.count(a)){
                p->children_[a]=new TrieNode(a);
            }
            p=p->children_[a];
        }
        p->is_end_= true;
    }

    bool search(string word) {
        auto p=root_;
        for (char a:word) {
            if (!p->children_.count(a)){
                return false;
            }
            p=p->children_[a];
        }
        return p->is_end_;
    }

    bool startsWith(string prefix) {
        auto p=root_;
        for (char a:prefix) {
            if (!p->children_.count(a)){
                return false;
            }
            p=p->children_[a];
        }
        return true;
    }
private:
    TrieNode* root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */