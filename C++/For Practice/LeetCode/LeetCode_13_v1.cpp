// 罗马数字转整数
// version 1

#include <iostream>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        int index = 0;
        int sum = 0;
        int flag = 0;
        string subs;
        while(index < s.length()){
            flag = 0;
            subs = s.substr(index, 2);
            // 确保能提取两个长度子串
            if(index < s.length - 2){
                switch(subs){
                    case "IV":
                        sum += 4;
                        index += 2;
                        flag = 1;
                        break;
                    case "IX":
                        sum += 9;
                        index += 2;
                        flag = 1;
                        break;
                    case "XL":
                        sum += 40;
                        index += 2;
                        flag = 1;
                        break;
                    case "XC":
                        sum += 90;
                        index += 2;
                        flag = 1;
                        break;
                    case "CD":
                        sum += 400;
                        index += 2;
                        flag = 1;
                        break;
                    case "CM":
                        sum += 900;
                        index += 2;
                        flag = 1;
                        break;
                    default:
                        break;
                }
            }
            if(flag == 0){
                subs = s.substr(index, 1);
                switch(subs){
                    case 'I':
                        sum += 1;
                        index += 1;
                        break;
                    case 'V':
                        sum += 5;
                        index += 1;
                        break;
                    case 'X':
                        sum += 10;
                        index += 1;
                        break;
                    case 'L':
                        sum += 50;
                        index += 1;
                        break;
                    case 'C':
                        sum += 100;
                        index += 1;
                        break;
                    case 'D':
                        sum += 500;
                        index += 1;
                        break;
                    case 'M':
                        sum += 1000;
                        index += 1;
                        break;
                    default:
                        break;
                }
            }
        }

        return sum;
    }
};

int main(){
    Solution test;
    int r;
    r = test.romanToInt("LVIII");


    return 0;
}
