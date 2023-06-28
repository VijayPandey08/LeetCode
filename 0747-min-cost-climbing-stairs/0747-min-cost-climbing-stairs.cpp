class Solution {
public:
    int min_cost(vector<int> & dp, vector<int> & cost, int n){
       if(n==0) return cost[0];
       if(n==1) return cost[1];
       
       if(dp[n]!=-1){
           return dp[n];
       }

       dp[n] = cost[n] + min(min_cost(dp, cost , n-1), min_cost(dp, cost , n-2));
       return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> dp(cost.size()+1,-1);
        return min_cost(dp, cost , cost.size()-1);
    }
};