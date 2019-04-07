// Add Binary

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int carry = 0;      //进位标志
        int i = a.size()-1, j = b.size()-1;
        //当有一个数组未结束或者存在进位的时候
        while(i>=0 || j>=0 || carry == 1){
            //carry不只是保留进位信息，还保留了当前位的整体信息
            if(i>=0)
                carry += a[i]-'0';
            if(j>=0)
                carry += b[j]-'0';
            //如果carry = 2，那么进位到下一位
            s = char(carry%2 + '0') + s;
            carry /= 2; //考虑c是2和3的情况，这两种情况下下次都需要进位
            i--;
            j--;
        }


        return s;
    }
};

int main(){
    Solution test;
    string res;
    string b = "101011001110001000000100011111011011111";
    string a = "110010000111011111110";

    res = test.addBinary(a, b);
    // res = test.addBinary("1010", "1011");
    cout << res << endl;

    return 0;
}
