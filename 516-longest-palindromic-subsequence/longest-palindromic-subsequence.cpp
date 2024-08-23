class Solution {
public:
    int solve(string& text1, string& text2, int i, int j,
              vector<vector<int>>& dp) {
        if (i >= text1.length() || j >= text2.length()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        if (text1[i] == text2[j]) {
            ans += 1 + solve(text1, text2, i + 1, j + 1, dp);
        } else {
            ans += max(solve(text1, text2, i + 1, j, dp),
                       solve(text1, text2, i, j + 1, dp));
        }

        return dp[i][j] = ans;
    }
    int longestPalindromeSubseq(string a) {
        int i = 0;
        int j = 0;
        string b = a;
        reverse(b.begin(), b.end());
        vector<vector<int>> dp(1005, vector<int>(1005, -1));

        return solve(a, b, i, j, dp);
    }
};