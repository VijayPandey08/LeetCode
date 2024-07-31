class Solution {
public:
vector<vector<int>> ans;
int n;

void solve(vector<int>& nums, int index, vector<int> temp){
    if(index>=n){
        ans.push_back(temp);
        return;
    }

    temp.push_back(nums[index]);
    solve(nums,index+1,temp);
    temp.pop_back();
    solve(nums,index+1,temp);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        int index=0;
        vector<int> temp;

        solve(nums,index,temp);
        return ans;

    }
};