class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        long long ans=0;
        int temp=0;
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi=max(maxi,nums[i]);
        }
        ans = (k)*(2*maxi + (k-1))/2;

        return ans;
        
    }
};