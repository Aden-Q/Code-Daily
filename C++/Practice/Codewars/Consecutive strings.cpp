//Codewars上一个题，给定一个string vector以及一个整数，返回首次出现的由ｋ个连续字符串组成的拼接字符串，其实很简单，但是时隔几个月再次拾起C++略感生疏

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string> &strarr, int k){
    	string f = "";
    	string test = "";
    	int begin = 0;
    	int end = begin + k;
    	int maxsize = 0;
    	while(end <= strarr.size()){
    		test = "";		//clear

    		for(int i = begin; i<end; i++)
    			test += strarr[i];		//concanate string
    		if(test.length()>maxsize){
    			maxsize = test.length();
    			f = test;		//copy
    		}
    		begin++;
    		end++;
    	}
    	return f;
    }
};

int main(void){
	LongestConsec test;
	std::vector<std::string> arr = {"zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"};
	std::string restring;
	restring = test.longestConsec(arr, 2);
	cout << restring << endl;
	return 0;
}
