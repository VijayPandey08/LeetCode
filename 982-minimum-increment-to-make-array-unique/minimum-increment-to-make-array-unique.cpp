class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int, int> m;
        // for(auto i:nums){
        //     m[i]++;
        // }

        sort(nums.begin(), nums.end());

        int ans = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                continue;
            } else if (nums[i] == nums[i - 1]) {
                ans++;
                nums[i] = nums[i] + 1;
                // continue;
            } else if (nums[i] < nums[i - 1]) {
                ans += abs(nums[i] - nums[i - 1]) + 1;
                nums[i] = nums[i] + abs(nums[i] - nums[i - 1]) + 1;
            }
        }

        // for(auto i:nums){
        //     cout<<i<<" ";
        // }

        return ans;
    }
};