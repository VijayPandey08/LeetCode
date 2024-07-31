class Solution {
public:
    vector<vector<int>> ans;
    int len;

    void solve(vector<int>& nums, int index, int k, int target,
               vector<int> temp) {
        if (temp.size() == k && target == 0) {
            ans.push_back(temp);
            return;
        }
        if (index >= len) {
            return;
        }
        temp.push_back(nums[index]);
        solve(nums, index + 1, k, target - nums[index], temp);
        temp.pop_back();
        solve(nums, index + 1, k, target, temp);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for (int i = 1; i <= 9; i++) {
            nums.push_back(i);
        }
        len = nums.size();
        int index = 0;

        vector<int> temp;
        solve(nums, index, k, n, temp);
        return ans;
    }
};