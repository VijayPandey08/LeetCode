class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (maxi < i)
                return false;
            maxi = max(maxi, i + nums[i]);
        }
        return true;
    }
};