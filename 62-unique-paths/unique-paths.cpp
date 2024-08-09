class Solution {
public:

int dp[101][101];

int solve(int m, int n,int i, int j){

    if(i==m && j==n){
        return 1;
    }

    if( i>m || j>n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = solve(m,n,i+1,j) + solve(m,n,i,j+1);
    return dp[i][j] = ans;

}
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        
        return solve(m-1,n-1,0,0);
    }
};