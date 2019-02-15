// Power of Two
// 98.30% time && 100.00% space
// AC
// recursion


#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
    	if(n <= 0)
    		return false;
    	else if(n == 1)
    		return true;
    	else if(n % 2 == 1)
    		return false;
    	else
    		return isPowerOfTwo(n/2);
    }
};

int main() {
	Solution test;
	bool res;
	res = test.isPowerOfTwo(1);
	cout << res << endl;
	res = test.isPowerOfTwo(16);
	cout << res << endl;
	res = test.isPowerOfTwo(218);
	cout << res << endl;

	return 0;
}