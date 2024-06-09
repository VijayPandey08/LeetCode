class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            dp[i]+=dp[i-1]+nums[i];
        }
        for(int i = 0;i<nums.size();i++){
            dp[i]%=k;
            if(dp[i]<0)dp[i]+=k;
        }
        map<int,int> m;
        m[0]++;
        for(int i = 0;i<nums.size();i++){
            ans+=m[dp[i]];
            m[dp[i]]++;
        }
        for(auto i:dp){
            cout<<i<<" ";
        }

        return ans;

    }
};