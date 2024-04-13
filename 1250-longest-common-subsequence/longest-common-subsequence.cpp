class Solution {
public:
int solve(string &text1, string &text2, int i, int j,vector<vector<int>> &dp){
    // base case
    if(i>= text1.length()) return 0;
    if(j>= text2.length()) return 0;

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    // recurssive call
    int ans=0;
    if(text1[i]==text2[j]){
        ans = 1 + solve(text1,text2,i+1,j+1,dp);
    }
    else{
                ans = max(solve(text1,text2,i,j+1,dp),solve(text1,text2,i+1,j,dp));

    }
    return dp[i][j]=ans;
}
    // Function to find the length of the longest common subsequence in two strings.
    int longestCommonSubsequence(string text1, string text2) {
        // int text1Length = text1.size(), text2Length = text2.size();
        // // Create a 2D array to store lengths of common subsequence at each index.
        // int dp[text1Length + 1][text2Length + 1];
      
        // // Initialize the 2D array with zero.
        // memset(dp, 0, sizeof dp);
      
        // // Loop through both strings and fill the dp array.
        // for (int i = 1; i <= text1Length; ++i) {
        //     for (int j = 1; j <= text2Length; ++j) {
        //         // If current characters match, add 1 to the length of the sequence
        //         // until the previous character from both strings.
        //         if (text1[i - 1] == text2[j - 1]) {
        //             dp[i][j] = dp[i - 1][j - 1] + 1;
        //         } else {
        //             // If current characters do not match, take the maximum length
        //             // achieved by either skipping the current character of text1 or text2.
        //             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        //         }
        //     }
        // }
      
        // // Return the value in the bottom-right cell which contains the
        // // length of the longest common subsequence for the entire strings.
        // return dp[text1Length][text2Length];
        int i=0;
        int j=0;
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        return solve(text1,text2,i,j,dp);
    }
};