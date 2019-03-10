// Happy Number
// Hashset
// 100.00% time and 100.00% space
// AC


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<int> set;
public:
    bool isHappy(int n) {
        int sum;
        bool res = false;
        int digit;

        while(true) {
            sum = 0;
            while(n > 0) {
                digit = n % 10;
                sum += digit*digit;
                n /= 10;
            }
            if(sum == 1) {
                res = true;
                break;
            }
            else if(set.count(sum) > 0)
                break;
            else
                set.insert(sum);
            n = sum;
        }

        return res;
    }
};

int main() {
    Solution test;
    bool res;
    res = test.isHappy(19);
    cout << res << endl;
    res = test.isHappy(2);
    cout << res << endl;

    return 0;
}
