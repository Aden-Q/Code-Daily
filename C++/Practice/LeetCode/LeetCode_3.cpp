//leetcode 3
//求最长连续子串，暴力遍历会超时，在嵌套循环里稍微修正一下就不会超时了


#include <iostream>
#include <set>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int olength = s.length();
        set<char> oset;
        int max_size = 0;
        for(int i = 0 ;i<s.length();i++)
            oset.insert(s[i]);
        for(int i = 0; i < s.length();i++){
            oset.clear();
            for(int j = i;j<s.length();j++){
                oset.insert(s[j]);
                if(oset.size() != j-i+1)
                    break;
                if(oset.size()>max_size)
                    max_size = oset.size();
            }
        }
        
        //for(set<char>::iterator it=oset.begin(); it!=oset.end(); it++)
        //    cout << *it <<endl;
        //cout << oset.size() << endl;

        return max_size;
    }
};

int main(){
    Solution test;
    int r;
    //r = test.lengthOfLongestSubstring("abcabcbb");
    //r = test.lengthOfLongestSubstring("bbbbb");
    cout << r << endl;
    
    return 0;
}
