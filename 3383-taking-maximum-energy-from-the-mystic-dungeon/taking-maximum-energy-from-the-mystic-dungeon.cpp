class Solution {
public:
    // int solve_dp(vector<int>& energy, int k, int i,vector<int> &dp) {
    //     if (i + k >= energy.size()) {
    //         return 0;
    //     }
    //     int ans=0;
    //     if (dp[i] != -1) {
    //         return dp[i];
    //     }
    //     for (int j = i; j < energy.size(); j+=k) {
    //         int include = energy[i] + solve_dp(energy, k, i + k,dp);
    //         int exclude = 0 + solve_dp(energy, k, i + 1,dp);
    //         ans+=max(include,exclude);
    //     }
    //     return dp[i] = ans;
    // }

    // int solve(vector<int>& energy, int k, int i) {
    //     int ans = 0;

    //     for (int j = i; j < energy.size(); j += k) {
    //         ans += energy[j];
    //     }
    //     return ans;
    // }
    
    int maximumEnergy(vector<int>& energy, int k) {
        // int maxi = INT_MIN;
        // for (int i = 0; i < energy.size(); i++) {
        //     maxi = max(maxi, solve(energy, k, i));
        // }
        // return maxi;


        // vector<int> dp(energy.size() + 1, -1);
        // int i=0;
        // return solve_dp(energy, k, i,dp);


        // ------ better approach -----
        // ek hi loop mein sare answer store kar lo, jisse TLE na aae
        // reverse karke jha se answer possible h, vha se answer store krte chale jaao aur fr maximum vala return kr dena
        reverse(energy.begin(),energy.end());
        for(int i=k; i<energy.size(); i++){
            energy[i]+=energy[i-k];
        }
        return *max_element(energy.begin(),energy.end());
    }
};