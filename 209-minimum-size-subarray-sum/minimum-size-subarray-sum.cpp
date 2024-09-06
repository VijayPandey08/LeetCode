class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0;
        int e = 0;

        int sum = 0;
        int ans = INT_MAX;

        while (e < nums.size()) {
            sum = sum + nums[e];

            while (s <= e && sum >= target) {
                ans = min(ans, e - s + 1);
                sum = sum - nums[s];
                s++;
            }

            e++;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};