#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s, t;
        stringstream ss;
        ss << x;
        ss >> s;
        t = s;
        if(x < 0)
            return false;
        reverse(s.begin(), s.end());
        for(int i=0;i<s.length();i++)
            if(s[i] != t[i])
                return false;
        return true;
    }
};

int main(){
    bool r;
    Solution test;
    r = test.isPalindrome(121);
    cout << r << endl;

    return 0;
}
