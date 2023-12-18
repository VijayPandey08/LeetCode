class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
       int ans=0;
       sort(nums.begin(),nums.end());
       int a=nums[0]*nums[1];
       int b=nums[nums.size()-1]*nums[nums.size()-2];
       ans=b-a;
       return ans;
    }
};