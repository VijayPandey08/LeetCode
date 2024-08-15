class Solution {
public:
    bool canJump(vector<int>& nums) {

        if (nums.size() == 1)
            return true;

        vector<bool> dpp(nums.size(), false);
        int n = dpp.size();
        dpp[n - 1] = true;

        for (int i = n - 2; i >= 0; i--) {

            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                dpp[i] = (dpp[i] | dpp[i + j]);
                if(dpp[i]) break;
            }
        }

        return dpp[0];


    }
};