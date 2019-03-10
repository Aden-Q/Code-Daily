// Intersection of Two Arrays
// 89.15% time and 100.00% space
// hashset AC


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    unordered_set<int> set;
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(auto it:nums1)
            set.insert(it);
        for(auto it:nums2) {
            if(set.count(it) > 0 && (find(res.begin(), res.end(), it) == res.end()))    // check duplicate
                res.push_back(it);
        }

        return res;
    }
};

int main() {
    Solution test;
    int num1[4] = {1,2,2,1};
    int num2[2] = {2,2};
    vector<int> nums1(num1, num1+4);
    vector<int> nums2(num2, num2+2);
    vector<int> res = test.intersection(nums1, nums2);
    for(auto it:res)
        cout << it << endl;

    return 0;
}
