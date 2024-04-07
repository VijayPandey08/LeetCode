class Solution {
public:

int solve_dp(int n, vector<int> &dp){
    if(n==0 || n==1){
        dp[n] = n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = solve_dp(n-1,dp) + solve_dp(n-2,dp);
    return dp[n];
}
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solve_dp(n,dp);
    }
};