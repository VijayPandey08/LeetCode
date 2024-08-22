class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int old_buy = -prices[0];
        int old_sell = 0;

        int new_buy = 0;
        int new_sell = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            // for buying new stock
            if (old_sell - prices[i] > old_buy) {
                new_buy = old_sell - prices[i];
            } else {
                new_buy = old_buy;
            }

            // for selling a stock
            if (prices[i] - fee + old_buy > old_sell) {
                new_sell = prices[i] - fee + old_buy;
            } else {
                new_sell = old_sell;
            }

            // updation after every iteration
            old_buy = new_buy;
            old_sell = new_sell;
        }

        return old_sell;
    }
};