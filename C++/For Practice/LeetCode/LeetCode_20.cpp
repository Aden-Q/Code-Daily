// Valid parentheses
// 这道题在CodeWars上面做过，用Java写的，现在用C++再写一遍
// 速度100%

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        char c, t;
        for(int i = 0;i<s.length();i++){
            c = s[i];
            if(ss.empty()){
                ss.push(c);
                continue;
            }
            else if(c=='(' || c=='[' || c=='{')
                ss.push(c);
            else{
                t = ss.top();
                if(c==')' && t=='(')
                    ss.pop();
                else if(c==']' && t=='[')
                    ss.pop();
                else if(c=='}' && t=='{')
                    ss.pop();
                else
                    ss.push(c);
            }

        }
        if(ss.empty())
            return true;
        else
            return false;
    }
};

int main(){
    Solution test;
    bool r;
    r = test.isValid("([)]");
    cout << r << endl;

    return 0;
}
