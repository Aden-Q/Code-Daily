// 一次遍历从左往右，记录当前所遇到的最低成本，以及当前遍历值与此最低成本
// 的差值，用另一个变量记录最大的那个差值，因为是从左往右的一次遍历，不用担心
// 就买入和出售的顺序问题
// 4ms 99.43% AC

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int cmincost = prices[0];
        int maxprofit = 0;
        int cprofit = 0;
        for (int i=0; i<prices.size(); i++){
            if (prices[i] < cmincost)
                cmincost = prices[i];
            cprofit = prices[i]-cmincost;
            if (cprofit > maxprofit)
                maxprofit = cprofit;
        }

        return maxprofit;
    }
};

int main (){
    Solution test;
    int  price[6] = {7, 1, 5, 3, 6, 4};
    vector<int> prices(price, price+6);
    int res;
    res = test.maxProfit(prices);
    cout << res << endl;
    return 0;
}
