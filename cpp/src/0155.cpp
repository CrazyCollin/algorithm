#include <stack>

class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        data_.push(val);
        if (min_.empty()||val<=min_.top()){
            min_.push(val);
        }
    }
    
    void pop() {
        if (data_.top()==min_.top()){
            min_.pop();
        }
        data_.pop();
    }
    
    int top() {
        return data_.top();
    }
    
    int getMin() {
        return min_.top();
    }
private:
    std::stack<int> data_;
    std::stack<int> min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */