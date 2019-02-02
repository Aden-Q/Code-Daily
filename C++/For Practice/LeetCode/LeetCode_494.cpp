// Target sum
// 40.68% time and 50.46% space beats
// simple implementation
// AC
// no reference

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int count = 0;

public:
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(nums, 0 , S);
        return count;
    }

    // assistant function, depth represents the depth of recursions
    void dfs(vector<int>& nums, int depth, int S) {
        if(depth == nums.size() && S == 0)
            count++;
        if(depth < nums.size()) {
            dfs(nums, depth+1, S-nums[depth]);
            dfs(nums, depth+1, S+nums[depth]);
        }
    }
};

int main(){
    Solution test;
    int num[5] = {1, 1, 1, 1, 1};
    vector<int> nums(num, num+5);
    int res;
    res = test.findTargetSumWays(nums, 3);

    cout << res << endl;

    return 0;
}