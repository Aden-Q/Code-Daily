// Implement Stack using Queues
// stupid solution with two queues, but AC :D
// 1.05% time and 0.55% space. AC, :D


#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
	queue<int> origin_queue;
	queue<int> help_queue;

public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        origin_queue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
    	int top;

    	if(origin_queue.size() == 1) {
    		top = origin_queue.front();
    		origin_queue.pop();
    	}

    	else {
    		while(origin_queue.size() > 1) {
    			help_queue.push(origin_queue.front());
    			origin_queue.pop();
    		}
    		top = origin_queue.front();
    		origin_queue.pop();

    		while(!help_queue.empty()) {
    			origin_queue.push(help_queue.front());
    			help_queue.pop();
    		}
    	}

    	return top;
    }
    
    /** Get the top element. */
    int top() {
    	if(origin_queue.size() == 1)
    		return origin_queue.front();
    	else {
    		while(origin_queue.size() > 1) {
    			help_queue.push(origin_queue.front());
    			origin_queue.pop();
    		}
    		int top = origin_queue.front();
    		help_queue.push(origin_queue.front());
    		origin_queue.pop();

    		while(!help_queue.empty()) {
    			origin_queue.push(help_queue.front());
    			help_queue.pop();
    		}

    		return top;
    	}
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return origin_queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */


int main() {
	MyStack stack;
	stack.push(1);
	stack.push(2);
	int param_1 = stack.top();
	int param_2 = stack.pop();
	int param_3 = stack.empty();

	cout << "param_1: " << param_1 << endl;
	cout << "param_2: " << param_2 << endl;
	cout << "param_3: " << param_3 << endl;
	cout << "param_4: " << param_4 << endl;

	return 0;
}