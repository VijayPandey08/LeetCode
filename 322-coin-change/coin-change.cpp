class Solution {
public:

int solve(vector<int> &coins, int amount, int ans, vector<int> &dp){
    if(amount ==0){
        return 0 ;
    }

    if(dp[amount]!=-1){
        return dp[amount];
    }

    int mini = INT_MAX;

    for(int i=0; i<coins.size(); i++){
        if(amount>=coins[i]){
            int ans = solve(coins,amount - coins[i], ans, dp);
            if(ans!=INT_MAX){
                mini = min(mini,1+ ans);
            }
        }
        
    }
        return dp[amount] = mini;
}
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        vector<int> dp(amount+1,-1);
        int temp = solve(coins,amount,ans,dp);


        if(temp==INT_MAX) return -1;
        return temp;
    }
};