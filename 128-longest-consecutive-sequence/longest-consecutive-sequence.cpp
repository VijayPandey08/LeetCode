class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans = 1;
        int count = 1;

        sort(nums.begin(),nums.end());
        for(auto i:nums){
            cout<<i<<" ";
        }

        for(int i=1; i<nums.size(); i++){
            if(abs(nums[i]-nums[i-1])==1){
                count++;
                ans = max(ans,count);
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                count=1;
            }
        } 
        return ans;
        
    }
};