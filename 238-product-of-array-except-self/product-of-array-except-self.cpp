class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            vector<int> ans(nums.size(),0);
            vector<int> pre(nums.size(),0);
            vector<int> suf(nums.size(),0);
            pre[0] = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                pre[i] = pre[i - 1] *nums[i];
            }
            reverse(nums.begin(), nums.end());
            suf[0] = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                suf[i] = suf[i - 1] *nums[i];
            }
            reverse(suf.begin(),suf.end());
            ans[0] = suf[1];
            ans[nums.size() - 1] = pre[nums.size() - 2];
            for (int i = 1; i < nums.size()-1; i++) {
                ans[i]=pre[i-1]*suf[i+1];
            }
            return ans;
        }
};