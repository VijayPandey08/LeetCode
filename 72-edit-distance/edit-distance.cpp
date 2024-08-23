class Solution {
public:
    int dp[505][505];
    int solve(string& a, string& b, int i, int j) {
        if (i >= a.length()) {
            return b.length() - j;
        }

        if (j >= b.length()) {
            return a.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == b[j]) {
            ans += 0 + solve(a, b, i + 1, j + 1);
        } else {
            int insert = 1 + solve(a, b, i, j + 1);
            int del = 1 + solve(a, b, i + 1, j);
            int replace = 1 + solve(a, b, i + 1, j + 1);

            ans += min({insert, del, replace});
        }

        return dp[i][j] = ans;
    }

    int minDistance(string a, string b) {
        memset(dp, -1, sizeof(dp));
        int i = 0;
        int j = 0;

        return solve(a, b, i, j);
    }
};