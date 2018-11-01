//寻找最长公共子串
//这也没啥技术含量呀，实现了就行了，比较好的应该是多指针的worse O(n)遍历吧

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        bool flag = true;
        char c;
        if(strs.size() == 0)
            return "";
        for(int i=0;i<strs[0].length();i++){
            c = strs[0][i]; //总是锁定第一个字符串
            for(int j=1;j<strs.size();j++){
                if(c!=strs[j][i]){
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                res += c;
            else
                break;
        }

        return res;
    }
};

int main(){
    Solution test;
    string res;
    string s[] = {"flower","flow","flight"};
    vector<string> vec(s,s+3);
    res = test.longestCommonPrefix(vec);
    cout << res << endl;
    
    return 0;
}
