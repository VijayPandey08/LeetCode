class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // we call this algorithm of finding maximum sub array as kadanes
        // algorithm
        int maxi = INT_MIN;
        // this is khandani way of finding max element
        int temp = 0;
        // this temp will help us in finding the max sum, lets see how
        for (int i = 0; i < nums.size(); i++) {
            temp += nums[i];        // makes sense
            maxi = max(maxi, temp); // so far so good
            if (temp < 0) {
                temp = 0; // killer move
            }
        }
        return maxi;
    }
};