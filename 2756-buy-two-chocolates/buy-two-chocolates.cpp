class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int ans=0;
        sort(prices.begin(),prices.end());
        if(money>=(prices[0]+prices[1])){
            return money-(prices[0]+prices[1]);
        }
        return money;
    }
};