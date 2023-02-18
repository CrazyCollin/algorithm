//
// Created by collin on 2023/2/3.
//
#include <queue>

//class MyStack {
//public:
//    std::queue<int> in,out;
//    MyStack() {
//
//    }
//
//    void push(int x) {
//        in.push(x);
//    }
//
//    int pop() {
//        while (in.size()!=1){
//            int tmp=in.front();
//            in.pop();
//            out.push(tmp);
//        }
//        int res=in.front();
//        in.pop();
//        while (!out.empty()){
//            int tmp=out.front();
//            out.pop();
//            in.push(tmp);
//        }
//        return res;
//    }
//
//    int top() {
//        return in.back();
//    }
//
//    bool empty() {
//        return in.empty();
//    }
//};

class MyStack {
public:
    std::queue<int> queue;
    MyStack() {

    }

    void push(int x) {
        queue.push(x);
    }

    int pop() {
        int size=queue.size();
        while (size!=1){
            int tmp=queue.front();
            queue.pop();
            queue.push(tmp);
            size-=1;
        }
        int res=queue.front();
        queue.pop();
        return res;
    }

    int top() {
        return queue.back();
    }

    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */