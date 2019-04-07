// 罗马数字转整数
// version 2

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<string, int> valueMap;
        valueMap.insert(pair<string, int>("I",1));
        valueMap.insert(pair<string, int>("V",5));
        valueMap.insert(pair<string, int>("X",10));
        valueMap.insert(pair<string, int>("L",50));
        valueMap.insert(pair<string, int>("C",100));
        valueMap.insert(pair<string, int>("D",500));
        valueMap.insert(pair<string, int>("M",1000));
        valueMap.insert(pair<string, int>("IV",4));
        valueMap.insert(pair<string, int>("IX",9));
        valueMap.insert(pair<string, int>("XL",40));
        valueMap.insert(pair<string, int>("XC",90));
        valueMap.insert(pair<string, int>("CD",400));
        valueMap.insert(pair<string, int>("CM",900));
        // return 0 if map failed, find function also works well
        int sum = 0;
        int index = 0;
        int flag = 0;
        string subs;
        while(index < s.length()){
            flag = 0;
            if(index+1<s.length()){
                subs = s.substr(index, 2); //length 2
                if(valueMap[subs]!=0){
                    sum += valueMap[subs];
                    flag = 1;
                    index += 2;
                }
            }
            if(flag == 0){
                subs = s.substr(index, 1);
                if(valueMap[subs]!=0){
                    sum += valueMap[subs];
                    index += 1;
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
    cout << r << endl;

    return 0;
}
