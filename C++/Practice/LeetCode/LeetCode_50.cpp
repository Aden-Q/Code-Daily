// 这个题目有毒，下面是AC的版本。。。

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1.0;
        if(n < 0 && n == INT_MIN)
        	return 1/x * myPow(1/x, INT_MAX);	// 单独处理一下这种最坑的情况
        else if(n < 0){
        	n = -n;
        	x = 1/x;
        }
        if(n % 2 == 0)
            return myPow(x*x, n/2);
        else
            return x * myPow(x*x, n/2);
    }
};

int main(){
    Solution test;
    double ans;
    ans = test.myPow(2.0, -2147483648);
    cout << ans << endl;
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;
    return 0;
}
