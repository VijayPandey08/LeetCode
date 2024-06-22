class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int oddCount = 0;
        m[oddCount] = 1;

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                oddCount++;
            }
            if (m.count(oddCount - k)) {
                ans += m[oddCount - k];
            }

            m[oddCount]++;
        }

        return ans;
    }
};