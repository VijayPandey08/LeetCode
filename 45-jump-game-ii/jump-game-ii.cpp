class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpp(nums.size(),INT_MAX);
        dpp[n-1] = 0;

        for(int i = n-2; i>=0; i--){
            int mini = INT_MAX;
            for(int j=1; j<=nums[i] && i+j<n; j++){
               mini = min(mini,dpp[i+j]);
            }
            if(mini!=INT_MAX){

            dpp[i] = 1 + mini;
            }
        }
for(auto i:dpp){
    cout<<i<<" ";
}

        return dpp[0];

    }
};