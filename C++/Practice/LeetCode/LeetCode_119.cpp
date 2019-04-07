// The first time, using tail recursion and time limit exceeded
// The second time update from the previous array. O(k) space
// AC, 100.00% time and 36.49% space
// iteration

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> res(rowIndex+1);
    	res[0] = 1;
    	// run (rowIndex+1) rounds in total
    	// each round updates from the previous round
    	for(int i=0; i<rowIndex+1; i++) {
    		for(int j=i; j>0; j--)
    			res[j] += res[j-1];
    	}
    	return res;
    }
};

int main() {
	Solution test;
	int row = 31;
	vector<int> res;
	res = test.getRow(row);
	for(auto iter:res)
		cout << iter << " ";
	cout << endl;

	return 0;
}