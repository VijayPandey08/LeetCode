class Solution {
public:
    int dp[505][505];
    int solve(vector<int>&arr,int l,int r){
        if(l==r) return arr[l];
        if(l>r) return 0;
        if(dp[l][r]!= -1) return dp[l][r];
        int option1 = arr[l] + min(solve(arr,l+2,r) , solve(arr,l+1,r-1));
        int option2 = arr[r] + min(solve(arr,l+1,r-1),solve(arr,l,r-2));

        return dp[l][r]=max(option1,option2);
    }

    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n = piles.size();
        int alice = solve(piles,0,n-1);
        int sum = accumulate(piles.begin(),piles.end(),0ll);
        int bob = sum - alice;

        return alice>bob;
    }
};