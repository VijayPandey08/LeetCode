class Solution {
public:
    int left_most(vector<int>& nums, int target, int s, int e, int mid) {
        int left = INT_MAX;

        while (s <= e) {
            if (nums[mid] == target) {
                left = min(mid, left);
                e = mid - 1;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
            mid = e - (e - s) / 2;
        }

        return left;
    }

    int right_most(vector<int>& nums, int target, int s, int e, int mid) {
        int right = INT_MIN;

        while (s <= e) {
            if (nums[mid] == target) {
                right = max(mid, right);
                s = mid + 1;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
            mid = e - (e - s) / 2;
        }

        return right;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;

        // long long left = INT_MAX;
        // long long right = INT_MIN;

        long long s = 0;
        long long e = nums.size() - 1;
        long long mid = e - (e - s) / 2;

        int left = left_most(nums, target, s, e, mid);
        int right = right_most(nums, target, s, e, mid);

        if (left == INT_MAX && right == INT_MIN)
            return {-1, -1};
        v.push_back(left);
        v.push_back(right);
        return v;
    }
};