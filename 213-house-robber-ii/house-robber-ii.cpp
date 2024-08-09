class Solution {
public:
 int rob2(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        if(nums.size()==1) return dp[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }

        return dp.back();
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> a,b;
        for(int i=0; i<nums.size(); i++){
           if(i==0){
            a.push_back(nums[i]);
            continue;
           }
           a.push_back(nums[i]);
           b.push_back(nums[i]);
        }
        a.pop_back();

        int temp1 = rob2(a);
        int temp2 = rob2(b);

        return max(temp1,temp2);
    }
};