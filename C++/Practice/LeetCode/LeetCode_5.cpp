// longest palindromic substring
// 暴力会超时
// Dynamic Programming O(n^2)
// 注意DP条件判断的时候有下陷阱

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s){
        int start=0, end=0;
        int maxlength = 1;
        int i, j, k;
        bool P[1005][1005] = {false};  // zero initialization
        for(i=0; i<s.length(); i++){       //base value
            P[i][i] = true;
            if(i+1<s.length() && s[i]==s[i+1]){
                P[i][i+1] = true;
                maxlength = 2;
                start = i;
                end = i+1;
            }
        }
        // k represents the length of substring
        for(k = 3; k <= s.length(); k++)
            for(i = 0; i+k-1 < s.length();i++){
                j = i+k-1;
                if(P[i+1][j-1] == true && s[i]==s[j]){
                    P[i][j] = true;
                    start = i;
                    end = j;
                    maxlength = j-i;
                }
                else
                    P[i][j] = false;
            }

        return s.substr(start, end-start+1);
    }
};

int main(){
    Solution test;
    string res;
    res = test.longestPalindrome("ccc");    
    cout << res << endl;
    return 0;
}
