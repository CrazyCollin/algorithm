//
// Created by collin on 2023/2/20.
//
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size()%2!=0){
            return false;
        }
        stack<char> symbol_stack;
        for (auto& item:s) {
            if (item=='('){
                symbol_stack.push(')');
            } else if (item=='['){
                symbol_stack.push(']');
            } else if (item=='{'){
                symbol_stack.push('}');
            } else if (symbol_stack.empty()||item!=symbol_stack.top()){
                return false;
            } else{
                symbol_stack.pop();
            }
        }
        return symbol_stack.empty();
    }
};