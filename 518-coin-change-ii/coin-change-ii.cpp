class Solution {
public:

int dp[5005][305];
int solve(int amount, vector<int> &coins, int index){
    if(amount==0){
        return 1;
    } 
    if(index>=coins.size() || amount<0){
        return 0;
    }

    if(dp[amount][index]!=-1){
        return dp[amount][index];
    }

    int a = solve(amount - coins[index], coins, index);
    int b = solve(amount, coins, index+1);

    return  dp[amount][index]= a+b;

}

    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int index = 0;
        return solve(amount,coins,index);
    }
};