class Solution {
public:
    int b_search(vector<int>& nums, int target, int s, int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;  // Correct mid calculation
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;  // Target not found
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int s = 0, e = n - 1;
        int mid = s + (e - s) / 2;
        int k = 0;  // Pivot index initialization

        // Find the pivot point where the array is rotated
        while (s <= e) {
            mid = s + (e - s) / 2;  // Correct mid calculation
            if (nums[mid] >= nums[0]) {
                s = mid + 1;
            } else {
                k = mid;
                e = mid - 1;
            }
        }

        // After pivot search, if k = 0, it means the array is not rotated
        if (k == 0) {
            return b_search(nums, target, 0, n - 1);  // Search in the entire array
        }

        // Binary search in the relevant half
        if (nums[k] <= target && target <= nums[n - 1]) {
            return b_search(nums, target, k, n - 1);  // Search in the right half
        } else {
            return b_search(nums, target, 0, k - 1);  // Search in the left half
        }
    }
};