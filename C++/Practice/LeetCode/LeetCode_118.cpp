// Pascal Triangle
// 5.43% time, 71.88% space
// AC, recursive implementation

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> temp;
        
        int i;
        for(i=1; i<=numRows; i++) {
        	temp.clear();
        	for(int j=1; j<=i; j++)
        		temp.push_back(pascalTriangle(i,j));
    		res.push_back(temp);	
    	}
    	return res;
    }
    
    int pascalTriangle(int row, int col) {
    	if(col == 1 || col == row)
    		return 1;
    	else
    		return pascalTriangle(row-1, col-1) + pascalTriangle(row-1, col);
    }
};

int main() {
	Solution test;
	int row = 5;
	vector<vector<int>> r = test.generate(row);
	for(auto it1:r) {
		for(auto it2:it1)
			cout << it2 << " ";
		cout << endl;
	}

	return 0;
}