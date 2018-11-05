// Sqrt(x)
// 97.76%

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        return int(sqrt(x)+0.0000001);
    }
};

int main(){
    Solution test;
    int res;
    res = test.mySqrt(4);
    cout << res << endl;

    return 0;
}
