// Isomorphic Strings
// 59.52% time && 100.00% space
// AC hashmap


#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_map<char, char> hashmap;
public:
    bool isIsomorphic(string s, string t) {
        vector<int> set;
        bool res = true;
        if(s.length() != t.length())
            return false;
        else {
            for(int i=0; i<s.length(); i++) {
                if(hashmap.count(s[i]) > 0) {
                    if(hashmap[s[i]] != t[i]) {
                        res = false;
                        break;
                    }
                }
                else {
                    hashmap.insert(make_pair(s[i], t[i]));
                    if(find(set.begin(), set.end(), t[i]) != set.end()) {
                        res = false;
                        break;
                    }
                    else
                        set.push_back(t[i]);
                }
            }
        }
        
        return res;
    }
};

int main() {
    Solution test1, test2, test3;
    bool res;
    string s = "ab";
    string t = "aa";
    res = test1.isIsomorphic(s, t);
    cout << "egg && add: " << res << endl;
    s = "foo";
    t = "bar";
    res = test2.isIsomorphic(s, t);
    cout << "foo && bar: " << res << endl;
    s = "paper";
    t = "title";
    res = test3.isIsomorphic(s, t);
    cout << "paper && title: " << res << endl;

    return 0;
}