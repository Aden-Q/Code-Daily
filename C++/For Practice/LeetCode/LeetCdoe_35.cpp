// Search insert position
// 这个写的就比较烂了，不过easy一刷仅仅只是为了实现

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size()-1;
        int mid;
        if(target < nums[0])
            return 0;
        else if(target > nums[end])
            return end+1;
        for(;begin<end;){
            mid = (begin+end)/2;
            if(nums[mid] == target)
                return mid;
            if(mid == begin)
                break;
            if(nums[mid]<target)
                begin = mid;
            else
                end = mid;
        }
        return end;
    }
};

int main(){
    Solution test;
    int res;
    int n[] = {1,3,5,6};
    vector<int> nums(n,n+4);
    res = test.searchInsert(nums, 0);
    cout << res << endl;

    return 0;
}
