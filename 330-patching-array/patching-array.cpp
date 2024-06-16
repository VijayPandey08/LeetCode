class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
// bdiya observation based question
// basic observation, we ll make an variable to check the largest number
// we can make, and if the next number in the nums is the exact number
// following are largest number then its fine we will take nums[i] and
// no patch will be required in such case, and if the nums[i] is not
// just 1 greater then our largest reached number then we ll have to
// patch the next greater number

        int patch = 0;
        int i = 0;
        long long max_reach = 0;

        // check max_reach kha tk ho skta h
        while (max_reach < n) {
            if (i < nums.size() && nums[i] <= (max_reach + 1)) {
                max_reach += nums[i];
                i++;
            } else {
                max_reach += (max_reach + 1);
                patch++;
            }
        }
        return patch;
    }
};