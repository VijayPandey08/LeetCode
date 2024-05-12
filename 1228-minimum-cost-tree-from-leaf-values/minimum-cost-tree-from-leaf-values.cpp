class Solution {
public:
    int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int s, int e,vector<vector<int>> &dp) {
        if (s > e)
            return 0;
        if (s == e)
            return 0;
        int ans = INT_MAX;
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        for (int i = s; i < e; i++) {
            // i is used here for partitioning
            ans = min(ans, (maxi[{s, i}] * maxi[{i + 1, e}]) +
                               solve(arr, maxi, s, i,dp) +
                               solve(arr, maxi, i + 1, e,dp));
        }
        return dp[s][e]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        // isme basically do part hein, pehle precompute krna pdega har  i->j
        // range ke lie ki kon max h, uske baad left subtree ka max uthao right
        // sub tree ka max uthao, unhe multiply krke add kro, frr left subtree
        // aur right subtree ke lie call krdo
        // pre computation:
        map<pair<int, int>, int> maxi;
        for (int i = 0; i < arr.size(); i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int s = 0;
        int e = n - 1;
        return solve(arr, maxi, s, e,dp);
    }
};