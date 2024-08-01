class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(vector<int>& nums, int index) {

        if (index >= n) {
            ans.push_back(nums);
            return;
        }
        for (int j = index; j < n; j++) {
            swap(nums[index], nums[j]);
            solve(nums, index+1);
            swap(nums[index], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        int index = 0;
        solve(nums, index);
        return ans;
    }
};