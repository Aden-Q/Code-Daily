// no extra vector but double size (more efficient)
// 86.92% time and 94.03% space beats
// AC


#include <iostream>
#include <vector>

using namespace std;

class MinStack {
private:
	// store data and implement basic operations
	vector<int> data;
	// keep minvalue;
	int min;

public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
    	if(data.empty())
    		min = INT32_MAX;
    	else
    		min = data.back();
        data.push_back(x);
        if(x < this->min)
        	min = x;
        data.push_back(min);
    }
    
    void pop() {
        data.pop_back();
        data.pop_back();
    }
    
    int top() {
        return data[data.size()-2];	// -2 will be wrong due to capacity != size
    }
    
    int getMin() {
        return data.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj;
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


int main(){
	int res;
	MinStack obj;	// allocate from the stack
	obj.push(-2);
	obj.push(0);
	obj.push(-3);
	res = obj.getMin();	// return -3
	cout << res << endl;
	obj.pop();
	res = obj.top();		// return 0
	cout << res << endl;
	res = obj.getMin();
	cout << res << endl;

	return 0;
}