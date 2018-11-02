// Length of Lase Word
// 这道题目唯一要题型的点是测试样例可能出现'a '这样的东西，然后这个在judge里面也是有个bug

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s=="")
            return 0;
        
        string res = "";
        int index = s.length()-1;
        while(s[index] == ' ')
            index--;
        while(index>=0 && s[index]!=' '){
            res += s[index];
            index--;
        }
        return res.length();
    }
};

int main(){
    Solution test;
    int res;
    res = test.lengthOfLastWord("a ");
    cout << res << endl;

    return 0;
}
