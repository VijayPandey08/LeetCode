class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;

        int maxi = INT_MIN;

        while (right < n) {

            if (nums[right] == 0) {
                k--;
                right++;
            }
            else{
                right++;
            }

            while (k < 0) {
                if (nums[left] == 0) {
                    k++;
                }
                left++;
            }

            maxi = max(maxi, right - left);
            // right++;
        }

        return maxi;
    }
};