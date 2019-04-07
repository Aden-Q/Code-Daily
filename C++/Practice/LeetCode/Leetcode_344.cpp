// Reverse String
// Easy recursive implementation
// In place algorithm
// 98.07% time, 10.23% space AC

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse_recursive(s, 0, s.size()-1);
    }
	
	void reverse_recursive(vector<char>& s, int start, int end) {
		if(end-start < 1)
			return;
		else {
			char temp = s[start];
			s[start] = s[end];
			s[end] = temp;
			reverse_recursive(s, start+1, end-1);
		}
	}
};

int main() {
	Solution test;
	char ss[] = {'h','e','l','l','o'};
	
	vector<char> s(ss, ss+5);
	test.reverseString(s);
	for(auto iter:s)
	cout << iter;
	cout << endl;

	return 0;
}