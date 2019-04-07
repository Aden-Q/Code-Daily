// 4ms 87.16 AC，赖皮方法

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums;
        int i, j;
        for(i=0, j=0;i<m && j<n;){
            if(i<m && j<n){
                if(nums1[i] < nums2[j])
                    nums.push_back(nums1[i++]);
                else
                    nums.push_back(nums2[j++]);
            }
        }

        if(i == m)
            for(; j<n; j++)
                nums.push_back(nums2[j]);
        if(j == n)
            for(; i<m; i++)
                nums.push_back(nums1[i]);

        for(int i=0; i<nums.size(); i++)
            nums1[i] = nums[i];
    }
};

int main() {
    Solution test;
    int num1[6] = {1,2,3,0,0,0};
    int m = 3;
    int num2[3] = {2,5,6};
    int n = 3;
    vector<int> nums1(num1, num1+6);
    vector<int> nums2(num2, num2+3);
    test.merge(nums1, m, nums2, n);

    return 0;
}



