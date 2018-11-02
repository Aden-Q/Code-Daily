// Generate Parentheses
// 这个brute force还是算了。。。
// 深搜100%

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        DFS(res, "", n, n);
        return res;
    }
    
    void DFS(vector<string>& res, string out, int left, int right){
        if(left>right) // string里面的左括号少于右括号，剪枝
            return;
        if(left == 0 && right == 0) // 都已经加入到out里
            res.push_back(out);
        else{
            if(left>0)
                DFS(res, out+'(', left-1, right);
            if(right>0)
                DFS(res, out+')', left, right-1);
        }
    }
};

int main(){
    Solution test;
    vector<string> res;
    vector<string>::iterator iter;
    res = test.generateParenthesis(3);
    for(iter=res.begin();iter!=res.end();iter++)
        cout << *iter << endl;

    return 0;
}
