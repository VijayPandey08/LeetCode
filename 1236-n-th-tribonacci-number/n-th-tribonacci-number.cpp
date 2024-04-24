class Solution {
public:

    // int tib(vector<int> &dp , int n){
    //     if(n==0) return 0;
    //     if(n==1) return 1;
    //     if(n==2) return 1;

    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }

    //     dp[n]= tib(dp, n-1)+tib(dp, n-2)+tib(dp, n-3);
    //     return dp[n];

        
         
    // }

    int tribonacci(int n) {
        // vector<int> dp(n+1,-1);
        // int ans=tib(dp , n);
        // return ans;

        long long a = 0;
        long long b = 1;
        long long c = 1;

        if(n==0) return a;
        if(n==1) return b;
        if(n==2) return c;

        long long d=0;

        for(int i=3; i<=n; i++){
           d = a + b + c;
           a=b;
           b=c;
           c=d;
        }

        return d;
     


    }
};