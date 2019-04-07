//Plus one
// 有坑
// 100%

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end = digits.size()-1;
        if(digits[end]!=9){
            digits[end]++;
            return digits;
        }
        else if(end==0){
            digits.push_back(0);
            digits[end]=1;
        }
        else{
            digits[end]=0;
            int i = end-1;
            int carry = 1;
            while(carry == 1 && i>=0){
                digits[i]++;
                if(digits[i]!=10)
                    carry=0;
                else if(i!=0){
                    digits[i]=0;
                    i--;
                }
                else if(i==0){
                    digits[i]=0;
                    digits.insert(digits.begin(),1);
                    i--;        // for break
                }
            }
        }

        return digits;
    }
};

int main(){
    Solution test;
    vector<int> res;
    int nums[] = {9};
    vector<int> vec(nums,nums+1);
    res = test.plusOne(vec);
    vector<int>::iterator iter;
    for(iter=res.begin();iter!=res.end();iter++)
        cout << *iter << endl;

    return 0;
}
