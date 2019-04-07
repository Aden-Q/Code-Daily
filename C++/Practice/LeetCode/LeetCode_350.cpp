// Intersection of Two Arrays II
// 86.50% time && 100.00% space
// AC
// Hashmap check duplicate

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
	unordered_map<int, int> hashmap;
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(auto it:nums1) {
        	if(hashmap.count(it) > 0)
        		hashmap[it]++;
        	else
        		hashmap[it] = 1;
        }
        for(auto it:nums2) {
        	if(hashmap.count(it) > 0) {
        		res.push_back(it);
        		hashmap[it]--;
        		if(hashmap[it] == 0)
        			hashmap.erase(it);
        	}
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
	vector<int> res;
	res = test.intersect(nums1, nums2);
	for(auto it:res)
		cout << it << endl;

	return 0;
}