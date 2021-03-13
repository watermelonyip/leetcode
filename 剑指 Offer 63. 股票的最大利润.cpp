/*
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
限制：0 <= 数组长度 <= 10^5.
思想：用两个变量分别来存储当前的最小值和当前最大利润。遍历数组，如果当前值减去最小值大于最大利润，则更新最大利润值，更新最大利润值后再更新最小值。
时间复杂度O(n)，空间复杂度O(1)。
注意的是，一开始想着的做法是：遍历数组，如果当前数字大于前一个，则把两个数字的差值加入到当前利润当中；否则当前利润重新计算。
这种方法只适用于找连续递增数组，当出现[7,1,5,3,6,4]的时候只能得到1买入，5卖出，最大利润4的结果；正确答案应该是1买入，6卖出，最大利润5。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int min = prices[0];
        int max_profit = 0;
        for(int i = 1; i < prices.size(); i++){
            if((prices[i] - min) > max_profit)
                max_profit = prices[i] - min;
            if(prices[i] < min)
                min = prices[i];
        }
        return max_profit;
    }
};
