#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> _stack;

    MinStack() {

    }
    
    void push(int val) {
        int minN;
        if(_stack.empty())
            minN = val;
        else
            minN = min(_stack.top(), val);
        _stack.push(val);
        _stack.push(minN);
    }
    
    void pop() {
        _stack.pop();
        _stack.pop();
    }
    
    int top() {
        if(_stack.empty())
            return _stack.top();
        int minN = _stack.top();
        _stack.pop();
        int res = _stack.top();
        _stack.push(minN);
        return res;
    }
    
    int getMin() {
        return _stack.top();
    }
};

int main()
{
    
    return 0;
}