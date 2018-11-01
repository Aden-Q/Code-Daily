// Implement strStr()
// 用string内置方法跑了98.39%。。。看来OO语言还是有好处的
// 简单题目，实现就行了呀


#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int flag;
        if(needle == "")
            return 0;
        else{
            flag = haystack.find(needle);
            if(!(flag < 0))
                return flag;
            else
                return -1;
        }
    }
};

int main(){
    Solution test;
    int res;
    res = test.strStr("hello", "ll");
    cout << res << endl;

    return 0;
}
