//
// Created by collin on 2023/2/3.
//

#include <stack>

using namespace std;

class MyQueue {
public:

    stack<int> in,out;
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if (out.empty()){
            fromIn2Out();
        }
        int res=out.top();
        out.pop();
        return res;
    }

    int peek() {
        int res=pop();
        out.push(res);
        return res;
    }

    bool empty() {
        if (in.empty()&&out.empty()){
            return true;
        }
        return false;
    }

    void fromIn2Out(){
        while (!in.empty()){
            int tmp=in.top();
            in.pop();
            out.push(tmp);
        }
    }


};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */