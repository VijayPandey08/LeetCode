class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int> &dp){
        // base case agar amount hi zero ho gya toh
        if(amount==0){
            return 0;
        }

        if(dp[amount]!=-1){
            return dp[amount];
        }
        // minimum ans chahiye toh isi mein store krke rkhenge
        int mini=INT_MAX;
        
        // sare coins select kr ske  islie loop chalaenge
        for(int i=0; i<coins.size(); i++){
            // kisi coin ko tab hi select krenge jab vo amount se chota ho
           if(amount>=coins[i]){
            // har coin ke lie ans
            int recursionkaans = solve(coins,amount-coins[i],dp);
            // is ans ko tab hi consider krenge jab vo int max na ho
            if(recursionkaans!=INT_MAX){
            int ans = 1 + recursionkaans;
            mini=min(mini,ans); // minimun maintain kr rhe h
            }
           }
        }
        dp[amount] = mini;
        return dp[amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=amount +1;
        vector<int> dp(n,-1);
        int temp = solve(coins,amount,dp);
        if(temp == INT_MAX ) return -1;  // int_max reh gya matlab amount nahi ban paya ese mein -1 hi return krna h
        else return temp;
    
    }
};