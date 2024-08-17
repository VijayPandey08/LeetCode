class Solution {
public:
    int solve(vector<int>& coins, int amount, int ans, vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }

        if (dp[amount] != -1) {
            return dp[amount];
        }

        int mini = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            if (amount >= coins[i]) {
                int ans = solve(coins, amount - coins[i], ans, dp);
                if (ans != INT_MAX) {
                    mini = min(mini, 1 + ans);
                }
            }
        }
        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {

        int ans = 0;
        vector<int> dp(amount + 1, -1);
        int temp = solve(coins, amount, ans, dp); // recurssion

        // ---------------- tabulation -------------- //

        vector<vector<int>> dpp(coins.size() + 1,
                                vector<int>(amount + 1, INT_MAX));

        for (int i = 0; i < dpp.size(); i++) {
            for (int j = 0; j < dpp[0].size(); j++) {
                if (i == 0 && j == 0) {
                    dpp[i][j] = 0;
                } else if (i == 0) {
                    dpp[i][j] = INT_MAX;

                } else if (j == 0) {
                    dpp[i][j] = 0;

                } else {
                    if(dpp[i-1][j]!=INT_MAX){
                        dpp[i][j] = dpp[i-1][j];
                    }
                    
                        if(j-coins[i-1]>=0){
                            if(dpp[i][j]>dpp[i][j-coins[i-1]]){
                            dpp[i][j] = dpp[i][j-coins[i-1]];
                            if(dpp[i][j]!= INT_MAX) dpp[i][j]++;
                            }
                        }
                    
                }

                // cout << dpp[i][j] << " ";
            }
            // cout << endl;
        }
        int a = dpp.size();
        int b = dpp[0].size();

        if (dpp[a - 1][b - 1] != INT_MAX) {
            return dpp[a - 1][b - 1];
        }
        return -1;

        if (temp == INT_MAX)
            return -1;
        return temp;
    }
};