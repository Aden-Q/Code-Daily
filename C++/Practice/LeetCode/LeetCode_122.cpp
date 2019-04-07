class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, j;
        int sum = 0;
        for(i = 0;i < prices.size(); i++)
        {
            for(j=i+1;j<prices.size() - 1;j++)
            {
                if(prices[j] < prices[i])
                    break;
                if(prices[j + 1]<prices[j])
                {
                    sum += prices[j] - prices[i];
                    i = j - 1;
                    break;
                }
            }
            if(j == prices.size() - 1 && prices[j] > prices[i])     //防止j在初始化的时候就退出循环的情况，加一个条件判断
            {
                sum += prices[j] - prices[i];
                break;
            }
        }
        return sum;
    }
};
