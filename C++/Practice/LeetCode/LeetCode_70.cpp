// Climbing Stairs
// DP implementation
// 100%，DP就是强

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int* dp = new int[n+1];     //0是空头
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<n+1;i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};

int main(){
    Solution test;
    int res;
    res = test.climbStairs(3);
    cout << res << endl;

    return 0;
}
