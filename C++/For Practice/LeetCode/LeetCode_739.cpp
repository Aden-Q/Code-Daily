// Daily temperature
// finding the next greater element in an array
// store the result index on a stack untill a warmer day is found or 0 instead
// paris like 73, 80, 74 are impossible, so the conclusion holds
// 90.20% time and 61.29% space, refering AC

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        stack<int> index;

        for(int i=0; i<result.size(); i++){
            // continuous comparasion and pop till unsatified
            while(!index.empty() && T[i] > T[index.top()]){
                result[index.top()] = i-index.top();
                index.pop();
            }

            index.push(i);
        }

        return result;
    }
};


int main(){
    Solution test;
    int a[8] = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> T(a, a+8);
    vector<int> res;

    res = test.dailyTemperatures(T);
    for(int i = 0; i < res.size(); i++)
        cout << res[i];
    cout << endl;

    return 0;
}