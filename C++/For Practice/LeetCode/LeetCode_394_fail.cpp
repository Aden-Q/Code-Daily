// Decode String
// LIFO -> Stack
// Fail. ):


#include <iostream>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    string decodeString(string s) {
        deque<char> dstring;
        string substring = "";
        string res = "";
        stack<int> repete;
        int i, j, k;
        // bug for nested
        for(i=0; i<s.length(); i++) {
            substring = "";
            j = 0;
            if(s[i]>='a' && s[i] <= 'z')
                dstring.push_back(s[i]);

            if(s[i]>='0' && s[i]<='9') {
                repete.push(s[i]-'0');
                j = i+2;
                while(s[j]>='a' && s[j]<='z')
                    dstring.push_back(s[j++]);
                dstring.push_back('*');       // divide substring

                if(s[j] == ']') {
                    int times = repete.top();
                    repete.pop();
                    if(dstring.front() == '*')
                        dstring.pop_front();
                    while(!dstring.empty() && dstring.front() != '*') {
                        substring += dstring.front();
                        dstring.pop_front();
                    }
                    i = j;
                    for(k=0; k<times; k++)
                    res += substring;

                }
                else if(s[j]>='0' && s[j]<='9') {
                    int num = s[j]-'0';
                    if(dstring.back() == '*')
                        dstring.pop_back();
                    int pbegin = j+2;
                    for(int k=0; k<num; k++) {
                        pbegin = j+2;
                        while(s[pbegin]>='a' && s[pbegin]<='z')
                            dstring.push_back(s[pbegin++]);
                    }
                    i = j+1;
                    continue;
                }
            }
        }
        
        //while(!repete.empty()) {
        //    int times = repete.top();
        //    repete.pop();
        //    substring = "";
        //    if(dstring.back() == '*')
        //        dstring.pop_back();
        //    while(!dstring.empty()) {
        //        substring += dstring.front();
        //        dstring.pop_front();
        //    }

        //    for(i=0; i<times; i++)
        //        res += substring;
        //}

        return res;
    }
};

int main() {
	Solution test;
	string s = "3[a]2[bc]";
	string res;
	res = test.decodeString(s);
	cout << "3[a]2[bc] decodes to: " << res << endl;
	s = "3[a2[c]]";
	res = test.decodeString(s);
	cout << "3[a2[c]] decodes to: " << res << endl;
	s =  "2[abc]3[cd]ef";
	res = test.decodeString(s);
	cout << "2[abc]3[cd]ef decodes to: " << res << endl;

	return 0;
}