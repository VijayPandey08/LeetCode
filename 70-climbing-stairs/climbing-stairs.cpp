class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 1 || n == 2) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);

        vector<int> table(n+1,-1);
        table[0]=1;
        table[1]=1;

        for(int i=2; i<table.size(); i++){
            table[i] = table[i-1] + table[i-2];
        }

        return table[n];

        // return solve(n, dp);
    }






};