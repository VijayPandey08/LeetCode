class Solution {
public:

    int tib(vector<int> &dp , int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;

        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n]= tib(dp, n-1)+tib(dp, n-2)+tib(dp, n-3);
        return dp[n];

        
         
    }

    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        int ans=tib(dp , n);
        return ans;
     


    }
};