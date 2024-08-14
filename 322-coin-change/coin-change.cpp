class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);

        dp[0] = 0;

        for(int i=1; i<amount+1; i++){
            int mini = INT_MAX;
            for(auto j:coins){
                if(i>=j){
                   mini = min(mini,dp[i-j]);
                }
            }
            if(mini!=INT_MAX){
                dp[i] = 1 +mini;
            }
        }

        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};