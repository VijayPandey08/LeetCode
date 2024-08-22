class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int old_buy = -prices[0];
        int old_sell = 0;
        int cool_down = 0;

        for (int i = 1; i < prices.size(); i++) {
            int new_buy = 0;
            int new_sell = 0;
            int new_cool_down = 0;

            if (cool_down - prices[i] > old_buy) {
                new_buy = cool_down - prices[i];
            } else {
                new_buy = old_buy;
            }

            if (prices[i] + old_buy > old_sell) {
                new_sell = prices[i] + old_buy;
            } else {
                new_sell = old_sell;
            }

            if (old_sell > cool_down) {
                new_cool_down = old_sell;
            } else {
                new_cool_down = cool_down;
            }

            old_sell = new_sell;
            old_buy = new_buy;
            cool_down = new_cool_down;
        }

        return old_sell;
    }
};