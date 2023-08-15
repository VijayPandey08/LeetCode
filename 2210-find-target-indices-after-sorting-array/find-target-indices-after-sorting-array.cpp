class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int s=0;
        int e=nums.size()-1;
        int n=0;
        sort(nums.begin(),nums.end());
        n = lower_bound(nums.begin(),nums.end(), target) - nums.begin(); 
        cout<<n<<" ";
        while(n<nums.size() && target==nums[n] ){
            ans.push_back(n);
            n++;
            
        }
        
        return ans;
    }
};