// Contains Duplicate II
// 77.84% time && 100.00% space
// AC
// Hashmap

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
private:
	unordered_map<int, int> hashmap;
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	int t = nums.size();
        int abs = INT_MAX;
        for(int i=0; i<t; i++) {
        	if(hashmap.count(nums[i]) > 0) {
        		if((i - hashmap[nums[i]]) < abs)
        			abs = i - hashmap[nums[i]];
        		hashmap[nums[i]] = i;
        	}
        	else {
        		hashmap[nums[i]] = i;
        	}
        }
        if(abs <= k)
        	return true;
        else
        	return false;
    }
};


int main() {
	bool res;
	int num1[4] = {1,2,3,1};
	int k1 = 3;
	int num2[4] = {1,0,1,1};
	int k2 = 1;
	int num3[6] = {1,2,3,1,2,3};
	int k3 = 2;
	vector<int> nums1(num1, num1+4);
	vector<int> nums2(num2, num2+4);
	vector<int> nums3(num3, num3+6);
	Solution test1, test2, test3;
	res = test1.containsNearbyDuplicate(nums1, k1);
	cout << res << endl;
	res = test2.containsNearbyDuplicate(nums2, k2);
	cout << res << endl;
	res = test3.containsNearbyDuplicate(nums3, k3);
	cout << res << endl;

	return 0;
}