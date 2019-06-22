Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

https://leetcode.com/problems/min-stack/

Runtime: 28 ms, faster than 94.77% of C++ online submissions for Min Stack.
Memory Usage: 16.9 MB, less than 48.31% of C++ online submissions for Min Stack.
