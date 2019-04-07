// 100.00% time and 5.06% space
// Fibonacci by memorizaton
// AC


#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
private:
	unordered_map<int, int> map;

public:
    int fib(int N) {
        if(map.count(N) != 0)
        	return map[N];
        if(N == 0 || N == 1) {
        	map[N] = N;
        	return N;
        }

        int val = fib(N-1) + fib(N-2);
        map[N] = val;

        return val; 
    }
};


int main(void) {
	int ans;
	Solution test;
	ans = test.fib(4);
	cout << ans << endl;

	return 0;
}