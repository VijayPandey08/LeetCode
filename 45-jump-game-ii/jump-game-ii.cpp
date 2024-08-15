class Solution {
public:
    unordered_map<int,int> m;
    int solve(vector<int>& nums, int index) {
        int n = nums.size();
        if (index == n - 1) {
            return 0;
        }
        if (index >= n) {
            return INT_MAX;
        }
        if(m.find(index)!= m.end()) return m[index];
        int mini = INT_MAX;
        for (int i = 1; i <= nums[index]; i++) {
            mini = min(mini, solve(nums, index+i));
        }
        if (mini == INT_MAX) return m[index] = mini;
        return m[index] = (mini + 1);
    }

    int jump(vector<int>& nums) {

        int index = 0;
        return solve(nums, index);

        //--------------- tabulation-----------------//
        int n = nums.size();
        vector<int> dpp(nums.size(), INT_MAX);
        dpp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            int mini = INT_MAX;
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                mini = min(mini, dpp[i + j]);
            }
            if (mini != INT_MAX) {

                dpp[i] = 1 + mini;
            }
        }
        for (auto i : dpp) {
            cout << i << " ";
        }

        return dpp[0];
    }
};