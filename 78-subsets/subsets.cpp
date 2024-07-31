class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(vector<int>& nums, int index, vector<int> temp) {
        // base case
        if (index >= n) {
            ans.push_back(temp);
            return;
        }

        // nums unique h, toh duplicate ki tension nhi
        // ya toh lo, ya nhi lo, baaat khtm

        temp.push_back(nums[index]); // inclusion
        solve(nums, index + 1, temp);

        temp.pop_back(); // backtracking
        solve(nums, index + 1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        int index = 0;
        vector<int> temp;

        solve(nums, index, temp);
        return ans;
    }
};