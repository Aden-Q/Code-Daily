// 最接近的三数之和
// 给定一个数组和一个目标值，找出数组中和最接近目标值的三个数

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int diff = 1000;  //记录差的绝对值，希望这个最小
       int diffsum = 0;
       int diff1, diff2, cdiff;
       int sum = 0;
       sort(nums.begin(), nums.end());

       vector<int>::iterator it1 = nums.begin();
       vector<int>::iterator it2 = nums.begin()+1;
       vector<int>::iterator it3 = nums.end()-1;
       for(;it1 < nums.end(); it1++)
            // slide it2 or it3
            for(it2=it1+1, it3 = nums.end()-1;it2<it3;){
               sum = *it1 + *it2 + *it3;
               cdiff = abs(sum-target);
               if(cdiff < diff){
                   diff = cdiff;
                   diffsum = sum;
               }
               if(it2+1<it3){
                   sum = *it1 + *(it2+1) + *(it3);
                   diff1 = abs(sum-target);
                   sum = *it1 + *(it2) + *(it3-1);
                   diff2 = abs(sum-target);
                   if(diff1<diff2)
                       it2++;
                   else
                       it3--;
               }
               else
                   it2++;  // in order to jump out of for loop
            }
       return diffsum;
    }
};

int main(){
    Solution test;
    int a[] = {-1, 2, 1, -4};
    vector<int> t(a, a + 4);
    int r;
    r = test.threeSumClosest(t, 1);
    cout << r << endl;

    return 0;
}
