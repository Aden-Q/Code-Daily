// Contains Duplicate
// HashSet && unordered set
// 73.49% time && 0.89% space AC
// HashSet

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_set<int> hashset;
public:
    bool containsDuplicate(vector<int>& nums) {
        for(auto it:nums) {
            if(hashset.count(it) > 0)
                return true;
            else
                hashset.insert(it);
        }
        return false;
        
    }
};

int main() {
    int test1[4] = {1, 2, 3, 1};
    int test2[4] = {1, 2, 3, 4};
    int test3[10] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    vector<int> test1_nums(test1, test1+4);
    vector<int> test2_nums(test2, test2+4);
    vector<int> test3_nums(test3, test3+10);
    Solution s1;
    Solution s2;
    Solution s3;
    bool res1, res2, res3;
    res1 = s1.containsDuplicate(test1_nums);
    res2 = s2.containsDuplicate(test2_nums);
    res3 = s3.containsDuplicate(test3_nums);
    cout << res1 << endl;
    cout << res2 << endl;
    cout << res3 << endl;
    return 0;
}
