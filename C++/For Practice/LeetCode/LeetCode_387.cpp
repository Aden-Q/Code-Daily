// First Unique Character in a String
// 17.26% time
// 100.00% space
// AC
// Hashmap

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
	unordered_map<char, int> hashmap;
public:
    int firstUniqChar(string s) {
        for(auto c:s) {
        	if(hashmap.count(c) > 0)
        		hashmap[c]++;
        	else
        		hashmap.insert(make_pair(c, 1));
        }

        for(int i=0; i < s.length(); i++)
        	if(hashmap[s[i]] == 1)
        		return i;
        return -1;
    }
};

int main() {
	Solution test;
	int res;
	res = test.firstUniqChar("loveleetcode");
	cout << res << endl;

	return 0;
}