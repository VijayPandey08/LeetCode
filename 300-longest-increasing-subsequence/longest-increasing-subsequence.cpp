class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> trail(nums.size(),0);
        trail[0] = 1;
        int ans = 1;
        for(int i = 1;i<nums.size();i++){
            int maxi = 0;
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]){
                    maxi = max(maxi,trail[j]);
                }
            }
            trail[i] = maxi+1;
            ans = max(ans,trail[i]);
        }
        return ans;
        
    }
};