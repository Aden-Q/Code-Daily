// 33.60% time and 0.88% space
// hashset, explore
// AC

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
private:
    unordered_set<int> hashset;
public:
    int singleNumber(vector<int>& nums) {
        for(auto it:nums) {
        	if(hashset.count(it) > 0)
            	hashset.erase(it);
            else
            	hashset.insert(it);
        }
        int flag;
        for(auto it:hashset) {
            flag = it;
        }

        return flag;
    }
};

int main() {
    Solution test;
    int num[5] = {4,1,2,1,4};
    vector<int> nums(num, num+5);
    int res;
    res = test.singleNumber(nums);
    cout << res << endl;

    return 0;
}
