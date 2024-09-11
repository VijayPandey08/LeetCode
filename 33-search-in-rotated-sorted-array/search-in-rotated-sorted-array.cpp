class Solution {
public:
    int b_search(vector<int>& nums, int target, int s, int e) {
        int ans = -1;
        int mid = 0;
        while (s <= e) {
            mid = e - (e - s) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {

        if (nums.size() == 1 && target == nums[0])
            return 0;
        if (nums.size() == 1 && target != nums[0])
            return -1;

        int k = 0; // k index is the pivot point lets find it first;

        int s = 0;
        int e = nums.size() - 1;
        int mid = e - (e - s) / 2;

        while (s <= e) {
            if (nums[mid] >= nums[0]) {
                s = mid + 1;
            } else if (nums[mid] < nums[0]) {
                k = mid;
                e = mid - 1;
            }
            mid = e - (e - s) / 2;
        }
        cout << k << endl;

        if (k == 0) {
            return b_search(nums, target, 0,
                            nums.size() - 1); // Search in the entire array
        }

        if (nums[k] <= target && target <= nums[nums.size() - 1])
            return b_search(nums, target, k, nums.size() - 1);

        if (nums[0] <= target && target <= nums[k - 1])
            return b_search(nums, target, 0, k - 1);

        return -1;
    }
};