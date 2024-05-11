class Solution {
public:
    int solve(int start, int end, vector<vector<int>>& dp) {
        if (start > end) {
            return 0;
            // matlab guess nahi kr skte, q ki n se bdi value ho gyi h
        }
        if (start == end) {
            return 0;
            // matlab jo dhund rhe the vo mil gya, ya ek hi element bcha h toh
            // usme kya dhundna
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans, max(i + solve(start, i - 1, dp),
                               i + solve(i + 1, end, dp)));
        }
        return dp[start][end] = ans;
    }
    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        vector<vector<int>> dp(n + 1, vector<int>(n+1,-1));
        int ans = solve(start, end, dp);
        return ans;
    }
};