class Solution {
public:

bool solve(string s, int idx,int sum,vector<vector<int>> &dp){
if(idx>=s.length()){
    if(sum==0) return true;
    else return false;
}
if(dp[idx][sum]!=-1){
    return dp[idx][sum];
}

bool ans=false;

     if(s[idx]=='('){
        ans = ans | solve(s,idx+1,sum+1,dp);
     }
     else if(s[idx]==')'){
        if(sum>0){
        ans = ans | solve(s,idx+1,sum-1,dp);
        }
        else{
            return dp[idx][sum] = false;
        }
     }
     else{
        ans = ans | solve(s,idx+1,sum+1,dp);
        ans = ans | solve(s,idx+1,sum,dp);
        if(sum>0){
        ans = ans | solve(s,idx+1,sum-1,dp);
        }
     }
     return dp[idx][sum] = ans;
}
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,-1));
        return solve(s,0,0,dp);
    }
};