// 100.00% time, 5.34% space
// AC
// recursion with memorization


#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
	unordered_map<int, int> map;

public:
    int climbStairs(int n) {
        if(map.count(n) != 0)
        	return map[n];
        if(n == 1 || n == 2) {
        	map[n] = n;
        	return n;
        }

        int ways = climbStairs(n-1) + climbStairs(n-2);
        map[n] = ways;
        return ways;
    }
};


int main(void) {
	Solution test;
	int ans = test.climbStairs(3);
	cout << ans << endl;
	
	return 0;
}