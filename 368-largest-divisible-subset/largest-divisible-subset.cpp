class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        int cnt = 1;
        for(int i = 1;i<n;i++){
            int maxi = 0;
            for(int j = 0;j<i;j++){
                if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0){
                    maxi = max(maxi,dp[j]);
                }
            }
            dp[i] = 1 + maxi;
            cnt = max(cnt,dp[i]);
        }
        // int cnt = *max_element(dp.begin(),dp.end());
        vector<int> ans;
        int last = -1;
        for(int i = n-1;i>=0;i--){
            if(last== -1){
                if(cnt==dp[i]){
                    last = nums[i];
                    ans.push_back(last);
                    cnt--;
                }
            }
            else{
                if(dp[i]==cnt && (nums[i]%last==0 || last%nums[i]==0)){
                    last = nums[i];
                    ans.push_back(last);
                    cnt--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};