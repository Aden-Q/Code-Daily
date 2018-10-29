// 整数逆序输出，简单思路就是先用string流转化为string，然后对字符串
// 做逆序，然后再转成整数。注意处理特殊情况就ok

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string s;
        string overflow;
        stringstream ss;
        stringstream k;
        int i;
        int flag = 1;

        if(x < 0){
            flag = -1;
            x = -x;
        }
        else if(x == 0)
            return x;

        ss << x;
        ss >> s;
        
        std::reverse(s.begin(), s.end());

        for(i=0;i<s.length();i++)
            if(s[i]!='0')
                break;
        s = s.substr(i, s.end()-s.begin()+i);

        x = flag * atoi(s.c_str());
        
        //防止溢出，这个设定只能说明原题比较蠢
        //ss.str("");
        k << flag * x;
        k >> overflow;
        if(overflow != s)
            return 0;


        return x;
    }
};

int main(){
    int r;
    Solution test;
    r = test.reverse(120);
    cout << r << endl;
    return 0;
}
