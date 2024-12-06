/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack
{
public:
    MinStack()
    {
    }
    stack<int> stk1, stk2;
    void push(int val)
    {
        stk1.push(val);
        if (stk2.empty() or val < stk2.top())
            stk2.push(val);
    }

    void pop()
    {
        if (stk2.top() == stk1.top())
            stk2.pop();
        stk1.pop();
    }

    int top()
    {
        return stk1.top();
    }

    int getMin()
    {
        return stk2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
