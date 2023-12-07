class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        vector<int> v;
        for(int i=1; i<=nums.size(); i++){
            // ans=i^nums[i];
            v.push_back(i);
        }
       for(int i=0; i<nums.size(); i++){
           ans=ans^nums[i]^v[i];
       }
       return ans;
    }
};