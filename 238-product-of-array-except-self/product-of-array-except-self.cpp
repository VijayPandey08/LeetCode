class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            vector<int> ans(nums.size(),0); // vector intialize kre//
            vector<int> pre(nums.size(),0);
            vector<int> suf(nums.size(),0);
            pre[0] = nums[0];
            for (int i = 1; i < nums.size(); i++) // prefix matrix 
            {
                pre[i] = pre[i - 1] *nums[i];
            }
            reverse(nums.begin(), nums.end()); // reverse kia suffix matrix nikalne ke lie,, (asani ho jaati h ese ulta krke multiply krne m)
            suf[0] = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                suf[i] = suf[i - 1] *nums[i];
            }
            reverse(suf.begin(),suf.end()); // reverse krke correct order nikal lia

            ans[0] = suf[1];                           
            ans[nums.size() - 1] = pre[nums.size() - 2];
// starting aur ending index constant aane h toh direct dal die

            for (int i = 1; i < nums.size()-1; i++) {
                ans[i]=pre[i-1]*suf[i+1];
            }
            return ans;
        }
};