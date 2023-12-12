class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int ans=0;
    sort(nums.rbegin(),nums.rend());
    ans=(nums[0]-1)*(nums[1]-1);
    return ans;   
    }
};