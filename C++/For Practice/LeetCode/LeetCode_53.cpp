// Maximum Subarrays

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxvalue = nums[0];   // 因为有最小整数做测试
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum > maxvalue)
                maxvalue = sum;
            sum = sum < 0? 0:sum;
        }

        return maxvalue;
    }
};

int main(){

    return 0;
}
