// Two Sum
// 98.04% time and 100.00% space
// AC
// Hashmap version

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_map<int, int> hashmap;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int index = -1;
        for(auto num:nums) {
            index++;
            if(hashmap.count(target-num) > 0) {
                res.push_back(hashmap[target-num]);
                res.push_back(index);
                break;
            }
            else
                hashmap.insert(make_pair(num, index));
        }

        return res;
    }
};

int main() {
    Solution test;
    int num[4] = {2, 7, 11, 15};
    int target = 9;
    vector<int> nums(num, num+4);
    vector<int> res = test.twoSum(nums, 9);

    for(auto it:res)
        cout << it << endl;

    return 0;
}