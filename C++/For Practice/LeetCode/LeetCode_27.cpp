// Remove Element
// 没看懂这个辣鸡题目的return value

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        for(int i=0;i<length;i++){
            if(nums[i]==val){
                nums.erase(nums.begin()+i);
                length--;
                i--;
            }
        }
        return length;
    }
};

int main(){
    Solution test;
    int res;
    int nums[] = {3,2,2,3]};
    vector<int> vec(nums, nums+4);
    res = test.removeElement(vec, 3);
    cout << res << endl;

    return 0;
}
