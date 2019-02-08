// implement Queue using Stacks (only simple operations on stack)
// 2.16% time, 0.23% space... zui le
// AC, spd

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
	stack<int> enterstack;
	stack<int> exitstack;


public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        enterstack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = peek();
        exitstack.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
    	if(!exitstack.empty())
    		return exitstack.top();
    	else {
	        while(!enterstack.empty()) {
	        	exitstack.push(enterstack.top());
	        	enterstack.pop();
	        }
        }

        return exitstack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return  enterstack.empty() && exitstack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

 int main()	{
 	MyQueue obj;
 	obj.push(x);
 	int param_2 = obj.pop();
 	int param_3 = obj.peek();
 	bool param_4 = obj.empty();

 	cout << "param_2: " + param_2 << endl;
 	cout << "param_3: " + param_3 << endl;
 	cout << "param_4: " + param_4 << endl; 

 	return 0;
 }